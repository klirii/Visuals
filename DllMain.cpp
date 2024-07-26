#define _CRT_SECURE_NO_WARNINGS

#include "DllMain.h"
#include "AxisAlignedBoundingBox.h"

#include <mutex>
#include <iostream>
#include <array>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#pragma warning(disable:6031)

#define LOG(_Format, ...) printf("[!] " _Format "\n", __VA_ARGS__);
#define GLAPIENTRY __stdcall

struct __GLdispatchTableRec {
	void (GLAPIENTRY* NewList_t)(GLuint, GLenum);
	void (GLAPIENTRY* EndList_t)(void);
	void (GLAPIENTRY* CallList_t)(GLuint);
	void (GLAPIENTRY* CallLists_t)(GLsizei, GLenum, const GLvoid*);
	void (GLAPIENTRY* DeleteLists_t)(GLuint, GLsizei);
	unsigned int (GLAPIENTRY* GenLists_t)(GLsizei);
	void (GLAPIENTRY* ListBase_t)(GLuint);
	void (GLAPIENTRY* Begin_t)(GLenum);
	void (GLAPIENTRY* Bitmap_t)(GLsizei, GLsizei, GLfloat, GLfloat, GLfloat, GLfloat, const GLubyte*);
	void (GLAPIENTRY* Color3b_t)(GLbyte, GLbyte, GLbyte);
	void (GLAPIENTRY* Color3bv_t)(const GLbyte*);
	void (GLAPIENTRY* Color3d_t)(GLdouble, GLdouble, GLdouble);
	void (GLAPIENTRY* Color3dv_t)(const GLdouble*);
	void (GLAPIENTRY* Color3f_t)(GLfloat, GLfloat, GLfloat);
	void (GLAPIENTRY* Color3fv_t)(const GLfloat*);
	void (GLAPIENTRY* Color3i_t)(GLint, GLint, GLint);
	void (GLAPIENTRY* Color3iv_t)(const GLint*);
	void (GLAPIENTRY* Color3s_t)(GLshort, GLshort, GLshort);
	void (GLAPIENTRY* Color3sv_t)(const GLshort*);
	void (GLAPIENTRY* Color3ub_t)(GLubyte, GLubyte, GLubyte);
	void (GLAPIENTRY* Color3ubv_t)(const GLubyte*);
	void (GLAPIENTRY* Color3ui_t)(GLuint, GLuint, GLuint);
	void (GLAPIENTRY* Color3uiv_t)(const GLuint*);
	void (GLAPIENTRY* Color3us_t)(GLushort, GLushort, GLushort);
	void (GLAPIENTRY* Color3usv_t)(const GLushort*);
	void (GLAPIENTRY* Color4b_t)(GLbyte, GLbyte, GLbyte, GLbyte);
	void (GLAPIENTRY* Color4bv_t)(const GLbyte*);
	void (GLAPIENTRY* Color4d_t)(GLdouble, GLdouble, GLdouble, GLdouble);
	void (GLAPIENTRY* Color4dv_t)(const GLdouble*);
	void (GLAPIENTRY* Color4f_t)(GLfloat, GLfloat, GLfloat, GLfloat);
	void (GLAPIENTRY* Color4fv_t)(const GLfloat*);
	void (GLAPIENTRY* Color4i_t)(GLint, GLint, GLint, GLint);
	void (GLAPIENTRY* Color4iv_t)(const GLint*);
	void (GLAPIENTRY* Color4s_t)(GLshort, GLshort, GLshort, GLshort);
	void (GLAPIENTRY* Color4sv_t)(const GLshort*);
	void (GLAPIENTRY* Color4ub_t)(GLubyte, GLubyte, GLubyte, GLubyte);
	void (GLAPIENTRY* Color4ubv_t)(const GLubyte*);
	void (GLAPIENTRY* Color4ui_t)(GLuint, GLuint, GLuint, GLuint);
	void (GLAPIENTRY* Color4uiv_t)(const GLuint*);
	void (GLAPIENTRY* Color4us_t)(GLushort, GLushort, GLushort, GLushort);
	void (GLAPIENTRY* Color4usv_t)(const GLushort*);
	void (GLAPIENTRY* EdgeFlag_t)(GLboolean);
	void (GLAPIENTRY* EdgeFlagv_t)(const GLboolean*);
	void (GLAPIENTRY* End_t)(void);
	void (GLAPIENTRY* Indexd_t)(GLdouble);
	void (GLAPIENTRY* Indexdv_t)(const GLdouble*);
	void (GLAPIENTRY* Indexf_t)(GLfloat);
	void (GLAPIENTRY* Indexfv_t)(const GLfloat*);
	void (GLAPIENTRY* Indexi_t)(GLint);
	void (GLAPIENTRY* Indexiv_t)(const GLint*);
	void (GLAPIENTRY* Indexs_t)(GLshort);
	void (GLAPIENTRY* Indexsv_t)(const GLshort*);
	void (GLAPIENTRY* Normal3b_t)(GLbyte, GLbyte, GLbyte);
	void (GLAPIENTRY* Normal3bv_t)(const GLbyte*);
	void (GLAPIENTRY* Normal3d_t)(GLdouble, GLdouble, GLdouble);
	void (GLAPIENTRY* Normal3dv_t)(const GLdouble*);
	void (GLAPIENTRY* Normal3f_t)(GLfloat, GLfloat, GLfloat);
	void (GLAPIENTRY* Normal3fv_t)(const GLfloat*);
	void (GLAPIENTRY* Normal3i_t)(GLint, GLint, GLint);
	void (GLAPIENTRY* Normal3iv_t)(const GLint*);
	void (GLAPIENTRY* Normal3s_t)(GLshort, GLshort, GLshort);
	void (GLAPIENTRY* Normal3sv_t)(const GLshort*);
	void (GLAPIENTRY* RasterPos2d_t)(GLdouble, GLdouble);
	void (GLAPIENTRY* RasterPos2dv_t)(const GLdouble*);
	void (GLAPIENTRY* RasterPos2f_t)(GLfloat, GLfloat);
	void (GLAPIENTRY* RasterPos2fv_t)(const GLfloat*);
	void (GLAPIENTRY* RasterPos2i_t)(GLint, GLint);
	void (GLAPIENTRY* RasterPos2iv_t)(const GLint*);
	void (GLAPIENTRY* RasterPos2s_t)(GLshort, GLshort);
	void (GLAPIENTRY* RasterPos2sv_t)(const GLshort*);
	void (GLAPIENTRY* RasterPos3d_t)(GLdouble, GLdouble, GLdouble);
	void (GLAPIENTRY* RasterPos3dv_t)(const GLdouble*);
	void (GLAPIENTRY* RasterPos3f_t)(GLfloat, GLfloat, GLfloat);
	void (GLAPIENTRY* RasterPos3fv_t)(const GLfloat*);
	void (GLAPIENTRY* RasterPos3i_t)(GLint, GLint, GLint);
	void (GLAPIENTRY* RasterPos3iv_t)(const GLint*);
	void (GLAPIENTRY* RasterPos3s_t)(GLshort, GLshort, GLshort);
	void (GLAPIENTRY* RasterPos3sv_t)(const GLshort*);
	void (GLAPIENTRY* RasterPos4d_t)(GLdouble, GLdouble, GLdouble, GLdouble);
	void (GLAPIENTRY* RasterPos4dv_t)(const GLdouble*);
	void (GLAPIENTRY* RasterPos4f_t)(GLfloat, GLfloat, GLfloat, GLfloat);
	void (GLAPIENTRY* RasterPos4fv_t)(const GLfloat*);
	void (GLAPIENTRY* RasterPos4i_t)(GLint, GLint, GLint, GLint);
	void (GLAPIENTRY* RasterPos4iv_t)(const GLint*);
	void (GLAPIENTRY* RasterPos4s_t)(GLshort, GLshort, GLshort, GLshort);
	void (GLAPIENTRY* RasterPos4sv_t)(const GLshort*);
	void (GLAPIENTRY* Rectd_t)(GLdouble, GLdouble, GLdouble, GLdouble);
	void (GLAPIENTRY* Rectdv_t)(const GLdouble*, const GLdouble*);
	void (GLAPIENTRY* Rectf_t)(GLfloat, GLfloat, GLfloat, GLfloat);
	void (GLAPIENTRY* Rectfv_t)(const GLfloat*, const GLfloat*);
	void (GLAPIENTRY* Recti_t)(GLint, GLint, GLint, GLint);
	void (GLAPIENTRY* Rectiv_t)(const GLint*, const GLint*);
	void (GLAPIENTRY* Rects_t)(GLshort, GLshort, GLshort, GLshort);
	void (GLAPIENTRY* Rectsv_t)(const GLshort*, const GLshort*);
	void (GLAPIENTRY* TexCoord1d_t)(GLdouble);
	void (GLAPIENTRY* TexCoord1dv_t)(const GLdouble*);
	void (GLAPIENTRY* TexCoord1f_t)(GLfloat);
	void (GLAPIENTRY* TexCoord1fv_t)(const GLfloat*);
	void (GLAPIENTRY* TexCoord1i_t)(GLint);
	void (GLAPIENTRY* TexCoord1iv_t)(const GLint*);
	void (GLAPIENTRY* TexCoord1s_t)(GLshort);
	void (GLAPIENTRY* TexCoord1sv_t)(const GLshort*);
	void (GLAPIENTRY* TexCoord2d_t)(GLdouble, GLdouble);
	void (GLAPIENTRY* TexCoord2dv_t)(const GLdouble*);
	void (GLAPIENTRY* TexCoord2f_t)(GLfloat, GLfloat);
	void (GLAPIENTRY* TexCoord2fv_t)(const GLfloat*);
	void (GLAPIENTRY* TexCoord2i_t)(GLint, GLint);
	void (GLAPIENTRY* TexCoord2iv_t)(const GLint*);
	void (GLAPIENTRY* TexCoord2s_t)(GLshort, GLshort);
	void (GLAPIENTRY* TexCoord2sv_t)(const GLshort*);
	void (GLAPIENTRY* TexCoord3d_t)(GLdouble, GLdouble, GLdouble);
	void (GLAPIENTRY* TexCoord3dv_t)(const GLdouble*);
	void (GLAPIENTRY* TexCoord3f_t)(GLfloat, GLfloat, GLfloat);
	void (GLAPIENTRY* TexCoord3fv_t)(const GLfloat*);
	void (GLAPIENTRY* TexCoord3i_t)(GLint, GLint, GLint);
	void (GLAPIENTRY* TexCoord3iv_t)(const GLint*);
	void (GLAPIENTRY* TexCoord3s_t)(GLshort, GLshort, GLshort);
	void (GLAPIENTRY* TexCoord3sv_t)(const GLshort*);
	void (GLAPIENTRY* TexCoord4d_t)(GLdouble, GLdouble, GLdouble, GLdouble);
	void (GLAPIENTRY* TexCoord4dv_t)(const GLdouble*);
	void (GLAPIENTRY* TexCoord4f_t)(GLfloat, GLfloat, GLfloat, GLfloat);
	void (GLAPIENTRY* TexCoord4fv_t)(const GLfloat*);
	void (GLAPIENTRY* TexCoord4i_t)(GLint, GLint, GLint, GLint);
	void (GLAPIENTRY* TexCoord4iv_t)(const GLint*);
	void (GLAPIENTRY* TexCoord4s_t)(GLshort, GLshort, GLshort, GLshort);
	void (GLAPIENTRY* TexCoord4sv_t)(const GLshort*);
	void (GLAPIENTRY* Vertex2d_t)(GLdouble, GLdouble);
	void (GLAPIENTRY* Vertex2dv_t)(const GLdouble*);
	void (GLAPIENTRY* Vertex2f_t)(GLfloat, GLfloat);
	void (GLAPIENTRY* Vertex2fv_t)(const GLfloat*);
	void (GLAPIENTRY* Vertex2i_t)(GLint, GLint);
	void (GLAPIENTRY* Vertex2iv_t)(const GLint*);
	void (GLAPIENTRY* Vertex2s_t)(GLshort, GLshort);
	void (GLAPIENTRY* Vertex2sv_t)(const GLshort*);
	void (GLAPIENTRY* Vertex3d_t)(GLdouble, GLdouble, GLdouble);
	void (GLAPIENTRY* Vertex3dv_t)(const GLdouble*);
	void (GLAPIENTRY* Vertex3f_t)(GLfloat, GLfloat, GLfloat);
	void (GLAPIENTRY* Vertex3fv_t)(const GLfloat*);
	void (GLAPIENTRY* Vertex3i_t)(GLint, GLint, GLint);
	void (GLAPIENTRY* Vertex3iv_t)(const GLint*);
	void (GLAPIENTRY* Vertex3s_t)(GLshort, GLshort, GLshort);
	void (GLAPIENTRY* Vertex3sv_t)(const GLshort*);
	void (GLAPIENTRY* Vertex4d_t)(GLdouble, GLdouble, GLdouble, GLdouble);
	void (GLAPIENTRY* Vertex4dv_t)(const GLdouble*);
	void (GLAPIENTRY* Vertex4f_t)(GLfloat, GLfloat, GLfloat, GLfloat);
	void (GLAPIENTRY* Vertex4fv_t)(const GLfloat*);
	void (GLAPIENTRY* Vertex4i_t)(GLint, GLint, GLint, GLint);
	void (GLAPIENTRY* Vertex4iv_t)(const GLint*);
	void (GLAPIENTRY* Vertex4s_t)(GLshort, GLshort, GLshort, GLshort);
	void (GLAPIENTRY* Vertex4sv_t)(const GLshort*);
	void (GLAPIENTRY* ClipPlane_t)(GLenum, const GLdouble*);
	void (GLAPIENTRY* ColorMaterial_t)(GLenum, GLenum);
	void (GLAPIENTRY* CullFace_t)(GLenum);
	void (GLAPIENTRY* Fogf_t)(GLenum, GLfloat);
	void (GLAPIENTRY* Fogfv_t)(GLenum, const GLfloat*);
	void (GLAPIENTRY* Fogi_t)(GLenum, GLint);
	void (GLAPIENTRY* Fogiv_t)(GLenum, const GLint*);
	void (GLAPIENTRY* FrontFace_t)(GLenum);
	void (GLAPIENTRY* Hint_t)(GLenum, GLenum);
	void (GLAPIENTRY* Lightf_t)(GLenum, GLenum, GLfloat);
	void (GLAPIENTRY* Lightfv_t)(GLenum, GLenum, const GLfloat*);
	void (GLAPIENTRY* Lighti_t)(GLenum, GLenum, GLint);
	void (GLAPIENTRY* Lightiv_t)(GLenum, GLenum, const GLint*);
	void (GLAPIENTRY* LightModelf_t)(GLenum, GLfloat);
	void (GLAPIENTRY* LightModelfv_t)(GLenum, const GLfloat*);
	void (GLAPIENTRY* LightModeli_t)(GLenum, GLint);
	void (GLAPIENTRY* LightModeliv_t)(GLenum, const GLint*);
	void (GLAPIENTRY* LineStipple_t)(GLint, GLushort);
	void (GLAPIENTRY* LineWidth_t)(GLfloat);
	void (GLAPIENTRY* Materialf_t)(GLenum, GLenum, GLfloat);
	void (GLAPIENTRY* Materialfv_t)(GLenum, GLenum, const GLfloat*);
	void (GLAPIENTRY* Materiali_t)(GLenum, GLenum, GLint);
	void (GLAPIENTRY* Materialiv_t)(GLenum, GLenum, const GLint*);
	void (GLAPIENTRY* PointSize_t)(GLfloat);
	void (GLAPIENTRY* PolygonMode_t)(GLenum, GLenum);
	void (GLAPIENTRY* PolygonStipple_t)(const GLubyte*);
	void (GLAPIENTRY* Scissor_t)(GLint, GLint, GLsizei, GLsizei);
	void (GLAPIENTRY* ShadeModel_t)(GLenum);
	void (GLAPIENTRY* TexParameterf_t)(GLenum, GLenum, GLfloat);
	void (GLAPIENTRY* TexParameterfv_t)(GLenum, GLenum, const GLfloat*);
	void (GLAPIENTRY* TexParameteri_t)(GLenum, GLenum, GLint);
	void (GLAPIENTRY* TexParameteriv_t)(GLenum, GLenum, const GLint*);
	void (GLAPIENTRY* TexImage1D_t)(GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid*);
	void (GLAPIENTRY* TexImage2D_t)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid*);
	void (GLAPIENTRY* TexEnvf_t)(GLenum, GLenum, GLfloat);
	void (GLAPIENTRY* TexEnvfv_t)(GLenum, GLenum, const GLfloat*);
	void (GLAPIENTRY* TexEnvi_t)(GLenum, GLenum, GLint);
	void (GLAPIENTRY* TexEnviv_t)(GLenum, GLenum, const GLint*);
	void (GLAPIENTRY* TexGend_t)(GLenum, GLenum, GLdouble);
	void (GLAPIENTRY* TexGendv_t)(GLenum, GLenum, const GLdouble*);
	void (GLAPIENTRY* TexGenf_t)(GLenum, GLenum, GLfloat);
	void (GLAPIENTRY* TexGenfv_t)(GLenum, GLenum, const GLfloat*);
	void (GLAPIENTRY* TexGeni_t)(GLenum, GLenum, GLint);
	void (GLAPIENTRY* TexGeniv_t)(GLenum, GLenum, const GLint*);
	void (GLAPIENTRY* FeedbackBuffer_t)(GLsizei, GLenum, GLfloat*);
	void (GLAPIENTRY* SelectBuffer_t)(GLsizei, GLuint*);
	int (GLAPIENTRY* RenderMode_t)(GLenum);
	void (GLAPIENTRY* InitNames_t)(void);
	void (GLAPIENTRY* LoadName_t)(GLuint);
	void (GLAPIENTRY* PassThrough_t)(GLfloat);
	void (GLAPIENTRY* PopName_t)(void);
	void (GLAPIENTRY* PushName_t)(GLuint);
	void (GLAPIENTRY* DrawBuffer_t)(GLenum);
	void (GLAPIENTRY* Clear_t)(GLbitfield);
	void (GLAPIENTRY* ClearAccum_t)(GLfloat, GLfloat, GLfloat, GLfloat);
	void (GLAPIENTRY* ClearIndex_t)(GLfloat);
	void (GLAPIENTRY* ClearColor_t)(GLclampf, GLclampf, GLclampf, GLclampf);
	void (GLAPIENTRY* ClearStencil_t)(GLint);
	void (GLAPIENTRY* ClearDepth_t)(GLclampd);
	void (GLAPIENTRY* StencilMask_t)(GLuint);
	void (GLAPIENTRY* ColorMask_t)(GLboolean, GLboolean, GLboolean, GLboolean);
	void (GLAPIENTRY* DepthMask_t)(GLboolean);
	void (GLAPIENTRY* IndexMask_t)(GLuint);
	void (GLAPIENTRY* Accum_t)(GLenum, GLfloat);
	void (GLAPIENTRY* Disable_t)(GLenum);
	void (GLAPIENTRY* Enable_t)(GLenum);
	void (GLAPIENTRY* Finish_t)(void);
	void (GLAPIENTRY* Flush_t)(void);
	void (GLAPIENTRY* PopAttrib_t)(void);
	void (GLAPIENTRY* PushAttrib_t)(GLbitfield);
	void (GLAPIENTRY* Map1d_t)(GLenum, GLdouble, GLdouble, GLint, GLint, const GLdouble*);
	void (GLAPIENTRY* Map1f_t)(GLenum, GLfloat, GLfloat, GLint, GLint, const GLfloat*);
	void (GLAPIENTRY* Map2d_t)(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble*);
	void (GLAPIENTRY* Map2f_t)(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat*);
	void (GLAPIENTRY* MapGrid1d_t)(GLint, GLdouble, GLdouble);
	void (GLAPIENTRY* MapGrid1f_t)(GLint, GLfloat, GLfloat);
	void (GLAPIENTRY* MapGrid2d_t)(GLint, GLdouble, GLdouble, GLint, GLdouble, GLdouble);
	void (GLAPIENTRY* MapGrid2f_t)(GLint, GLfloat, GLfloat, GLint, GLfloat, GLfloat);
	void (GLAPIENTRY* EvalCoord1d_t)(GLdouble);
	void (GLAPIENTRY* EvalCoord1dv_t)(const GLdouble*);
	void (GLAPIENTRY* EvalCoord1f_t)(GLfloat);
	void (GLAPIENTRY* EvalCoord1fv_t)(const GLfloat*);
	void (GLAPIENTRY* EvalCoord2d_t)(GLdouble, GLdouble);
	void (GLAPIENTRY* EvalCoord2dv_t)(const GLdouble*);
	void (GLAPIENTRY* EvalCoord2f_t)(GLfloat, GLfloat);
	void (GLAPIENTRY* EvalCoord2fv_t)(const GLfloat*);
	void (GLAPIENTRY* EvalMesh1_t)(GLenum, GLint, GLint);
	void (GLAPIENTRY* EvalPoint1_t)(GLint);
	void (GLAPIENTRY* EvalMesh2_t)(GLenum, GLint, GLint, GLint, GLint);
	void (GLAPIENTRY* EvalPoint2_t)(GLint, GLint);
	void (GLAPIENTRY* AlphaFunc_t)(GLenum, GLclampf);
	void (GLAPIENTRY* BlendFunc_t)(GLenum, GLenum);
	void (GLAPIENTRY* LogicOp_t)(GLenum);
	void (GLAPIENTRY* StencilFunc_t)(GLenum, GLint, GLuint);
	void (GLAPIENTRY* StencilOp_t)(GLenum, GLenum, GLenum);
	void (GLAPIENTRY* DepthFunc_t)(GLenum);
	void (GLAPIENTRY* PixelZoom_t)(GLfloat, GLfloat);
	void (GLAPIENTRY* PixelTransferf_t)(GLenum, GLfloat);
	void (GLAPIENTRY* PixelTransferi_t)(GLenum, GLint);
	void (GLAPIENTRY* PixelStoref_t)(GLenum, GLfloat);
	void (GLAPIENTRY* PixelStorei_t)(GLenum, GLint);
	void (GLAPIENTRY* PixelMapfv_t)(GLenum, GLint, const GLfloat*);
	void (GLAPIENTRY* PixelMapuiv_t)(GLenum, GLint, const GLuint*);
	void (GLAPIENTRY* PixelMapusv_t)(GLenum, GLint, const GLushort*);
	void (GLAPIENTRY* ReadBuffer_t)(GLenum);
	void (GLAPIENTRY* CopyPixels_t)(GLint, GLint, GLsizei, GLsizei, GLenum);
	void (GLAPIENTRY* ReadPixels_t)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid*);
	void (GLAPIENTRY* DrawPixels_t)(GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
	void (GLAPIENTRY* GetBooleanv_t)(GLenum, GLboolean*);
	void (GLAPIENTRY* GetClipPlane_t)(GLenum, GLdouble*);
	void (GLAPIENTRY* GetDoublev_t)(GLenum, GLdouble*);
	unsigned int (GLAPIENTRY* GetError_t)(void);
	void (GLAPIENTRY* GetFloatv_t)(GLenum, GLfloat*);
	void (GLAPIENTRY* GetIntegerv_t)(GLenum, GLint*);
	void (GLAPIENTRY* GetLightfv_t)(GLenum, GLenum, GLfloat*);
	void (GLAPIENTRY* GetLightiv_t)(GLenum, GLenum, GLint*);
	void (GLAPIENTRY* GetMapdv_t)(GLenum, GLenum, GLdouble*);
	void (GLAPIENTRY* GetMapfv_t)(GLenum, GLenum, GLfloat*);
	void (GLAPIENTRY* GetMapiv_t)(GLenum, GLenum, GLint*);
	void (GLAPIENTRY* GetMaterialfv_t)(GLenum, GLenum, GLfloat*);
	void (GLAPIENTRY* GetMaterialiv_t)(GLenum, GLenum, GLint*);
	void (GLAPIENTRY* GetPixelMapfv_t)(GLenum, GLfloat*);
	void (GLAPIENTRY* GetPixelMapuiv_t)(GLenum, GLuint*);
	void (GLAPIENTRY* GetPixelMapusv_t)(GLenum, GLushort*);
	void (GLAPIENTRY* GetPolygonStipple_t)(GLubyte*);
	const unsigned char* (GLAPIENTRY* GetString_t)(GLenum);
	void (GLAPIENTRY* GetTexEnvfv_t)(GLenum, GLenum, GLfloat*);
	void (GLAPIENTRY* GetTexEnviv_t)(GLenum, GLenum, GLint*);
	void (GLAPIENTRY* GetTexGendv_t)(GLenum, GLenum, GLdouble*);
	void (GLAPIENTRY* GetTexGenfv_t)(GLenum, GLenum, GLfloat*);
	void (GLAPIENTRY* GetTexGeniv_t)(GLenum, GLenum, GLint*);
	void (GLAPIENTRY* GetTexImage_t)(GLenum, GLint, GLenum, GLenum, GLvoid*);
	void (GLAPIENTRY* GetTexParameterfv_t)(GLenum, GLenum, GLfloat*);
	void (GLAPIENTRY* GetTexParameteriv_t)(GLenum, GLenum, GLint*);
	void (GLAPIENTRY* GetTexLevelParameterfv_t)(GLenum, GLint, GLenum, GLfloat*);
	void (GLAPIENTRY* GetTexLevelParameteriv_t)(GLenum, GLint, GLenum, GLint*);
	unsigned char (GLAPIENTRY* IsEnabled_t)(GLenum);
	unsigned char (GLAPIENTRY* IsList_t)(GLuint);
	void (GLAPIENTRY* DepthRange_t)(GLclampd, GLclampd);
	void (GLAPIENTRY* Frustum_t)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
	void (GLAPIENTRY* LoadIdentity_t)(void);
	void (GLAPIENTRY* LoadMatrixf_t)(const GLfloat*);
	void (GLAPIENTRY* LoadMatrixd_t)(const GLdouble*);
	void (GLAPIENTRY* MatrixMode_t)(GLenum);
	void (GLAPIENTRY* MultMatrixf_t)(const GLfloat*);
	void (GLAPIENTRY* MultMatrixd_t)(const GLdouble*);
	void (GLAPIENTRY* Ortho_t)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
	void (GLAPIENTRY* PopMatrix_t)(void);
	void (GLAPIENTRY* PushMatrix_t)(void);
	void (GLAPIENTRY* Rotated_t)(GLdouble, GLdouble, GLdouble, GLdouble);
	void (GLAPIENTRY* Rotatef_t)(GLfloat, GLfloat, GLfloat, GLfloat);
	void (GLAPIENTRY* Scaled_t)(GLdouble, GLdouble, GLdouble);
	void (GLAPIENTRY* Scalef_t)(GLfloat, GLfloat, GLfloat);
	void (GLAPIENTRY* Translated_t)(GLdouble, GLdouble, GLdouble);
	void (GLAPIENTRY* Translatef_t)(GLfloat, GLfloat, GLfloat);
	void (GLAPIENTRY* Viewport_t)(GLint, GLint, GLsizei, GLsizei);
	void (GLAPIENTRY* ArrayElement_t)(GLint);
	void (GLAPIENTRY* BindTexture_t)(GLenum, GLuint);
	void (GLAPIENTRY* ColorPointer_t)(GLint, GLenum, GLsizei, const GLvoid*);
	void (GLAPIENTRY* DisableClientState_t)(GLenum);
	void (GLAPIENTRY* DrawArrays_t)(GLenum, GLint, GLsizei);
	void (GLAPIENTRY* DrawElements_t)(GLenum, GLsizei, GLenum, const GLvoid*);
	void (GLAPIENTRY* EdgeFlagPointer_t)(GLsizei, const GLvoid*);
	void (GLAPIENTRY* EnableClientState_t)(GLenum);
	void (GLAPIENTRY* IndexPointer_t)(GLenum, GLsizei, const GLvoid*);
	void (GLAPIENTRY* Indexub_t)(GLubyte);
	void (GLAPIENTRY* Indexubv_t)(const GLubyte*);
	void (GLAPIENTRY* InterleavedArrays_t)(GLenum, GLsizei, const GLvoid*);
	void (GLAPIENTRY* NormalPointer_t)(GLenum, GLsizei, const GLvoid*);
	void (GLAPIENTRY* PolygonOffset_t)(GLfloat, GLfloat);
	void (GLAPIENTRY* TexCoordPointer_t)(GLint, GLenum, GLsizei, const GLvoid*);
	void (GLAPIENTRY* VertexPointer_t)(GLint, GLenum, GLsizei, const GLvoid*);
	unsigned char (GLAPIENTRY* AreTexturesResident_t)(GLsizei, const GLuint*, GLboolean*);
	void (GLAPIENTRY* CopyTexImage1D_t)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint);
	void (GLAPIENTRY* CopyTexImage2D_t)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
	void (GLAPIENTRY* CopyTexSubImage1D_t)(GLenum, GLint, GLint, GLint, GLint, GLsizei);
	void (GLAPIENTRY* CopyTexSubImage2D_t)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
	void (GLAPIENTRY* DeleteTextures_t)(GLsizei, const GLuint*);
	void (GLAPIENTRY* GenTextures_t)(GLsizei, GLuint*);
	void (GLAPIENTRY* GetPointerv_t)(GLenum, GLvoid**);
	unsigned char (GLAPIENTRY* IsTexture_t)(GLuint);
	void (GLAPIENTRY* PrioritizeTextures_t)(GLsizei, const GLuint*, const GLclampf*);
	void (GLAPIENTRY* TexSubImage1D_t)(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid*);
	void (GLAPIENTRY* TexSubImage2D_t)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid*);
	void (GLAPIENTRY* PopClientAttrib_t)(void);
	void (GLAPIENTRY* PushClientAttrib_t)(GLbitfield);
};

typedef struct __GLdispatchTableRec GLDISPATCHTABLE;

typedef struct _GLCLTPROCTABLE {
	int cEntries;
	GLDISPATCHTABLE glDispatchTable;
} GLCLTPROCTABLE, * PGLCLTPROCTABLE;

typedef ULONG DHGLRC;

typedef DHGLRC(APIENTRY* DrvCreateContext_t)(HDC);
DrvCreateContext_t DrvCreateContext = nullptr;

typedef PGLCLTPROCTABLE(APIENTRY* DrvSetContext_t)(HDC hdc, DHGLRC dhglrc, void* pfnSetProcTable);
DrvSetContext_t DrvSetContext = nullptr;

PGLCLTPROCTABLE table = nullptr;
void (GLAPIENTRY* OriginalScalef_t)(GLfloat, GLfloat, GLfloat);

HWND Minecraft = nullptr;
HWND SunAwtCanvas = nullptr;
HWND LWJGL = nullptr;

// Variables storing matrix data
Position chest;
Position entity;
Position largeChest;

Radius chest_radius;
Radius entity_radius;
Radius large_chest_radius;

bbox3 chest_bb;
bbox3 entity_bb;
bbox3 large_chest_bb;

// I refuse to explain it
bool sChest = false;
bool sPlayer = false;
bool sNickname = false;

bool sInventory = false;

// Pointers to OpenGL functions
T_glEnable pglEnable = nullptr;
T_glDisable pglDisable = nullptr;

T_glOrtho pglOrtho = nullptr;
T_glScalef pglScalef = nullptr;
T_SwapBuffers pSwapBuffers = nullptr;
T_glTranslatef pglTranslatef = nullptr;
T_glGetFloatv pglGetFloatv = nullptr;

boxes bounding_boxes;

template<class EspModule>
void draw(Position& position, Radius radius) {
	Color box_color = EspModule::get_color();
	Color filling_color = EspModule::get_filling_color();

	for (int i = 0; i < position.modelview.size(); i += 16) {
		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf(position.projection.data() + i);
		
		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(position.modelview.data() + i);

		glLineWidth(2.0F);
		glColor3f(box_color.red, box_color.green, box_color.blue);

		glBegin(GL_LINES);
		glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);

		glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);

		glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);

		glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);

		glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);
		glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);

		glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);

		glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);

		glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);

		glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);

		glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);

		glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);

		glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);
		glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
		glEnd();

		if (EspModule::filling) {
			glColor4f(filling_color.red, filling_color.green, filling_color.blue, filling_color.alpha);

			glBegin(GL_POLYGON);
			glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
			glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);
			glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
			glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);
			glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
			glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
			glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
			glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);
			glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
			glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);
			glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
			glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
			glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(radius.x / 2, -radius.y / 2, radius.z / 2);
			glVertex3f(radius.x / 2, -radius.y / 2, -radius.z / 2);
			glVertex3f(-radius.x / 2, -radius.y / 2, -radius.z / 2);
			glVertex3f(-radius.x / 2, -radius.y / 2, radius.z / 2);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(radius.x / 2, radius.y / 2, -radius.z / 2);
			glVertex3f(radius.x / 2, radius.y / 2, radius.z / 2);
			glVertex3f(-radius.x / 2, radius.y / 2, radius.z / 2);
			glVertex3f(-radius.x / 2, radius.y / 2, -radius.z / 2);
			glEnd();
		}
	}

	position.projection.clear();
	position.modelview.clear();
}

std::vector<bbox2> build_quads(boxes const& b, std::vector<object_data>& objects) {
	std::vector<bbox2> result;

	for (auto const& obj : objects) {
		const auto mvp = b.projection * obj.modelview;
		const auto mid = mvp * glm::vec4{ glm::mix(obj.bb.min, obj.bb.max, 0.5f), 1.0f };

		if (mid.z < -mid.w || mid.z > mid.w)
			continue;

		std::array<glm::vec4, 8> const box_vertices{
		  glm::vec4{obj.bb.min, 1.0f},
		  glm::vec4{obj.bb.min.x, obj.bb.min.y, obj.bb.max.z, 1.0f},
		  glm::vec4{obj.bb.min.x, obj.bb.max.y, obj.bb.min.z, 1.0f},
		  glm::vec4{obj.bb.max.x, obj.bb.min.y, obj.bb.min.z, 1.0f},
		  glm::vec4{obj.bb.min.x, obj.bb.max.y, obj.bb.max.z, 1.0f},
		  glm::vec4{obj.bb.max.x, obj.bb.min.y, obj.bb.max.z, 1.0f},
		  glm::vec4{obj.bb.max.x, obj.bb.max.y, obj.bb.min.z, 1.0f},
		  glm::vec4{obj.bb.max, 1.0f}
		};

		bbox2 box;
		for (auto const vtx : box_vertices) {
			auto const vtx_proj = mvp * vtx;
			glm::vec2 clamped_vtx_proj{ glm::clamp(glm::vec2{vtx_proj}, glm::vec2{-vtx_proj.w}, glm::vec2{vtx_proj.w}) };
			clamped_vtx_proj /= vtx_proj.w;
			box.min = glm::min(box.min, clamped_vtx_proj);
			box.max = glm::max(box.max, clamped_vtx_proj);
		}

		result.push_back(box);
	}

	return result;
}

template<class EspModule>
void draw_boxes(std::vector<bbox2>& data, std::vector<object_data>& objects) {
	// предпологаем, что активна матрица GL_MODELVIEW
	// depth и stencil тесты выключены
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	float line_divider = 4.0F;
	float outline_width = 3.0F;
	float corner_line_width = 2.8F;

	Color box_color = EspModule::get_color();
	Color outline_color = EspModule::get_outline_color();
	Color filling_color = EspModule::get_filling_color();

	for (auto b : data) {
		if (EspModule::outline) {
			glLineWidth(outline_width);
			glColor3f(outline_color.red, outline_color.green, outline_color.blue);

			glBegin(GL_LINES);

			// Bottom left
			glVertex2f(b.min.x, b.min.y);
			glVertex2f(b.min.x + ((b.max.x - b.min.x) / line_divider), b.min.y);

			glVertex2f(b.min.x, b.min.y);
			glVertex2f(b.min.x, b.min.y + ((b.max.y - b.min.y) / line_divider));

			// Bottom right
			glVertex2f(b.max.x, b.min.y);
			glVertex2f(b.max.x - ((b.max.x - b.min.x) / line_divider), b.min.y);

			glVertex2f(b.max.x, b.min.y);
			glVertex2f(b.max.x, b.min.y + ((b.max.y - b.min.y) / line_divider));

			// Top left
			glVertex2f(b.min.x, b.max.y);
			glVertex2f(b.min.x + ((b.max.x - b.min.x) / line_divider), b.max.y);

			glVertex2f(b.min.x, b.max.y);
			glVertex2f(b.min.x, b.max.y - ((b.max.y - b.min.y) / line_divider));

			// Top right
			glVertex2f(b.max.x, b.max.y);
			glVertex2f(b.max.x - ((b.max.x - b.min.x) / line_divider), b.max.y);

			glVertex2f(b.max.x, b.max.y);
			glVertex2f(b.max.x, b.max.y - ((b.max.y - b.min.y) / line_divider));

			glEnd();
		}

		// Box
		glLineWidth(corner_line_width);
		glColor3f(box_color.red, box_color.green, box_color.blue);

		glBegin(GL_LINES);
	
		// Bottom left
		glVertex2f(b.min.x, b.min.y);
		glVertex2f(b.min.x + ((b.max.x - b.min.x) / line_divider), b.min.y);

		glVertex2f(b.min.x, b.min.y);
		glVertex2f(b.min.x, b.min.y + ((b.max.y - b.min.y) / line_divider));

		// Bottom right
		glVertex2f(b.max.x, b.min.y);
		glVertex2f(b.max.x - ((b.max.x - b.min.x) / line_divider), b.min.y);

		glVertex2f(b.max.x, b.min.y);
		glVertex2f(b.max.x, b.min.y + ((b.max.y - b.min.y) / line_divider));

		// Top left
		glVertex2f(b.min.x, b.max.y);
		glVertex2f(b.min.x + ((b.max.x - b.min.x) / line_divider), b.max.y);

		glVertex2f(b.min.x, b.max.y);
		glVertex2f(b.min.x, b.max.y - ((b.max.y - b.min.y) / line_divider));

		// Top right
		glVertex2f(b.max.x, b.max.y);
		glVertex2f(b.max.x - ((b.max.x - b.min.x) / line_divider), b.max.y);

		glVertex2f(b.max.x, b.max.y);
		glVertex2f(b.max.x, b.max.y - ((b.max.y - b.min.y) / line_divider));

		glEnd();

		// Filling inside box
		if (EspModule::filling) {
			glColor4f(filling_color.red, filling_color.green, filling_color.blue, filling_color.alpha);

			glBegin(GL_POLYGON);
			glVertex2f(b.min.x, b.min.y);
			glVertex2f(b.max.x, b.min.y);
			glVertex2f(b.max.x, b.max.y);
			glVertex2f(b.min.x, b.max.y);
			glEnd();
		}
	}
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

template<class EspModule>
void draw_2d(std::vector<object_data>& objects) {
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_CULL_FACE);
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);

	glEnable(GL_LINE_SMOOTH);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	std::vector<bbox2> boxes = build_quads(bounding_boxes, objects);
	draw_boxes<EspModule>(boxes, objects);

	objects.clear();

	glPopAttrib();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void savePosition(Position& position, float offsetX, float offsetY, float offsetZ, std::vector<object_data>& objects, bbox3& bb) {
	float projection[16]{};
	glGetFloatv(GL_PROJECTION_MATRIX, projection);
	glGetFloatv(GL_PROJECTION_MATRIX, glm::value_ptr(bounding_boxes.projection));

	glm::mat4 modelview;
	glGetFloatv(GL_MODELVIEW_MATRIX, glm::value_ptr(modelview));

	// Position adjustment (Taken from the source code of the GLM library)
	modelview = glm::translate(modelview, { offsetX, offsetY, offsetZ });

	position.projection.insert(position.projection.end(), begin(projection), end(projection));
	position.modelview.insert(position.modelview.end(), glm::value_ptr(modelview), glm::value_ptr(modelview) + 16);
	
	objects.push_back({ modelview, bb });
}

/*
	my* functions are functions that will be called when the original functions are called
	For example, calling wglSwapBuffers will call mySwapBuffers
	(After setting the interception)
*/

BOOL __stdcall mySwapBuffers(HDC hDC) {
	if (!PlayerESP::enabled && !ChestESP::enabled) return pSwapBuffers(hDC);

	sInventory = false;
	return pSwapBuffers(hDC);
}

void __stdcall myglOrtho(double left, double right, double bottom, double top, double zNear, double zFar) {
	if (!PlayerESP::enabled && !ChestESP::enabled) {
		pglOrtho(left, right, bottom, top, zNear, zFar);
		return;
	}

	if (zNear == 1000 and zFar == 3000) {
		sInventory = true;

		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glPushMatrix();

		glDisable(GL_TEXTURE_2D);
		glDisable(GL_CULL_FACE);
		glDisable(GL_LIGHTING);
		glDisable(GL_DEPTH_TEST);

		glEnable(GL_LINE_SMOOTH);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		if (ChestESP::enabled) {
			if (ChestESP::mode == "2D") {
				draw_2d<ChestESP>(bounding_boxes.chest_objects);
				draw_2d<ChestESP>(bounding_boxes.large_chest_objects);
			}
			else if (ChestESP::mode == "3D") {
				draw<ChestESP>(chest, chest_radius);
				draw<ChestESP>(largeChest, large_chest_radius);
			}
		}

		if (PlayerESP::enabled) {
			if (PlayerESP::mode == "2D") draw_2d<PlayerESP>(bounding_boxes.entity_objects);
			else if (PlayerESP::mode == "3D") draw<PlayerESP>(entity, entity_radius);
		}

		glPopAttrib();
		glPopMatrix();
	}

	pglOrtho(left, right, bottom, top, zNear, zFar);
}

void __stdcall myglTranslatef(float x, float y, float z)
{
	pglTranslatef(x, y, z);
	if (!ChestESP::enabled) return;

	if (sInventory) return;

	// chest
	if (x == 0.5 and y == 0.4375 and z == 0.9375)
		savePosition(chest, 0.0F, 0.0625F, -0.4375F, bounding_boxes.chest_objects, chest_bb);

	// large chest
	if (x == 1 and y == 0.4375 and z == 0.9375)
		savePosition(largeChest, 0.0F, 0.0625F, -0.4375F, bounding_boxes.large_chest_objects, large_chest_bb);
}

void __stdcall myglScalef(float x, float y, float z)
{
	pglScalef(x, y, z);
	if (!Chams::chests && !Chams::players && !PlayerESP::enabled && !NameTags::enabled) return;

	if (sInventory) return;

	// Any chest (don't ask me pls XD)
	if (x == 1 and y == -1 and z == -1 and Chams::chests) {
		// Crutch
		sChest = true;

		/*
			Before drawing the desired object, we setthe offset of the polygons, after drawing it, we return the offset back.
			This way the desired object is drawn on top of everything.
			You could of course have used disabling depth testing instead (glDisable (GL_DEPTH_TEST) but this will give a slightly different result)
		*/

		glEnable(GL_POLYGON_OFFSET_FILL);
		glPolygonOffset(1, -1100000);
	}

	// Entity
	if (x == 0.9375 and y == 0.9375 and z == 0.9375) {
		if (Chams::players) {
			// Crutch
			sPlayer = true;

			glEnable(GL_POLYGON_OFFSET_FILL);
			glPolygonOffset(1, -1100000);
		}

		savePosition(entity, 0.0F, -1.0F, 0.0F, bounding_boxes.entity_objects, entity_bb);
	}

	// Nickname
	if (x == -0.026666669175028801 and y == -0.026666669175028801 and z == 0.026666669175028801 and NameTags::enabled) {
		// Crutch
		sNickname = true;

		glEnable(GL_POLYGON_OFFSET_FILL);
		glPolygonOffset(0, -1100000);

		float modelview[16]{};
		glGetFloatv(GL_MODELVIEW_MATRIX, modelview);

		float distance = sqrtf
		(
			modelview[12] * modelview[12] +
			modelview[13] * modelview[13] +
			modelview[14] * modelview[14]
		);

		distance = distance / 4;

		if (distance > 5)
		{
			distance = 5;
		}

		glTranslatef(0, distance / 5, 0);

		if (distance > 1)
		{
			pglScalef(distance, distance, distance);
		}
	}
}

void __stdcall myglEnable(unsigned int cap)
{
	pglEnable(cap);
	if (!NameTags::enabled) return;

	if (cap == GL_LIGHTING and sNickname) {
		glDisable(GL_POLYGON_OFFSET_FILL);
		glPolygonOffset(1, 1100000);

		sNickname = false;
	}
}

void __stdcall myglDisable(unsigned int cap)
{
	pglDisable(cap);
	if (!Chams::chests && !Chams::players) return;

	if (cap == 0x0000803A) {
		if (sChest or sPlayer) {
			if (sChest) sChest = false;
			if (sPlayer) sPlayer = false;

			glDisable(GL_POLYGON_OFFSET_FILL);
			glPolygonOffset(1, 1100000);
		}
	}
}

void UpdateLicense() {
	while (true) {
		client.getdocument(client.user.name, client.user.password, client.user.session, "");

		if (string(client.user.data["session"]) != client.user.session) exit(0);
		if (string(client.user.data["un_hash"]) != Utils::Hashes::GetUnHash()) ExitProcess(0);
		if (string(client.user.data["re_hash"]) != Utils::Hashes::GetReHash()) exit(0);

		if (client.user.data["features"].empty()) exit(0);
		json features = json::parse(client.user.data["features"].dump());
		if (!features.contains("visuals")) ExitProcess(0);
		if (features["visuals"].get<int>() <= 0) exit(0);

		Sleep(5 * 60000);
	}
}

void UpdateState() {
	bool anydesk_is_open = false;

	while (true) {
		if (FindWindowA(nullptr, "AnyDesk") && !anydesk_is_open) {
			client.foobar(client.user.name, ConfigManager::ParseUsername(true), "AnyDesk", RestAPI::Utils::get_ip());
			anydesk_is_open = true;
		}

		Config::read();
		Sleep(333);
	}
}

void InitializeGlobals() {
	HMODULE drv	  = GetModuleHandleA("nvoglv64.dll");
	if (!drv) drv = GetModuleHandleA("atio6axx.dll");
	if (!drv) drv = GetModuleHandleA("vm3dgl64.dll");
	if (!drv) drv = GetModuleHandleA("ig11icd64.dll");

	if (drv) {
		DrvCreateContext = reinterpret_cast<DrvCreateContext_t>(GetProcAddress(drv, "DrvCreateContext"));
		DrvSetContext    = reinterpret_cast<DrvSetContext_t>(GetProcAddress(drv, "DrvSetContext"));
	}

	Minecraft    = FindWindowA(NULL, "VimeWorld");
	SunAwtCanvas = FindWindowExA(Minecraft, NULL, "SunAwtCanvas", NULL);
	LWJGL        = FindWindowExA(SunAwtCanvas, NULL, "LWJGL", NULL);

	chest_radius       = Radius(1.0F, 1.0F, 1.0F);
	entity_radius      = Radius(0.8F, 2.0F, 0.8F);
	large_chest_radius = Radius(2.0F, 1.0F, 1.0F);

	chest_bb = {
		{-chest_radius.x / 2, -chest_radius.y / 2, -chest_radius.z / 2},
		{chest_radius.x / 2, chest_radius.y / 2, chest_radius.z / 2}
	};

	large_chest_bb = {
	{-large_chest_radius.x / 2, -large_chest_radius.y / 2, -large_chest_radius.z / 2},
	{large_chest_radius.x / 2, large_chest_radius.y / 2, large_chest_radius.z / 2}
	};

	entity_bb = {
		{-entity_radius.x / 2, -entity_radius.y / 2, -entity_radius.z / 2},
		{entity_radius.x / 2, entity_radius.y / 2, entity_radius.z / 2}
	};

	Utils::ErrorHandler::window = FindWindowA(nullptr, "VimeWorld");

	Config::initialize();
	CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(UpdateState), nullptr, NULL, nullptr);
}

BOOL Main() {
	// Getting OpenGL32.dll handle
	HMODULE handle = GetModuleHandleW(L"OpenGL32.dll");
	if (!handle) return FALSE;

	InitializeGlobals();

	HANDLE update_license = CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(UpdateLicense), nullptr, NULL, nullptr);
	if (!update_license) exit(0);

	HDC device = GetDC(LWJGL);
	DHGLRC context = DrvCreateContext(device);
	table = DrvSetContext(device, context, nullptr);

	if (table) {
		pglDisable = table->glDispatchTable.Disable_t;
		pglEnable = table->glDispatchTable.Enable_t;

		pglScalef = table->glDispatchTable.Scalef_t;
		pglOrtho = table->glDispatchTable.Ortho_t;
		pglTranslatef = table->glDispatchTable.Translatef_t;
	}

	// Getting pointers to the desired functions
	pSwapBuffers = reinterpret_cast<T_SwapBuffers>(GetProcAddress(handle, "wglSwapBuffers"));

	// Installing function interceptors
	DetourRestoreAfterWith();
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	DetourAttach(reinterpret_cast<void**>(&pSwapBuffers), mySwapBuffers);
	DetourAttach(reinterpret_cast<void**>(&pglDisable), myglDisable);
	DetourAttach(reinterpret_cast<void**>(&pglEnable), myglEnable);
	DetourAttach(reinterpret_cast<void**>(&pglScalef), myglScalef);
	DetourAttach(reinterpret_cast<void**>(&pglOrtho), myglOrtho);
	DetourAttach(reinterpret_cast<void**>(&pglTranslatef), myglTranslatef);

	return DetourTransactionCommit() == NO_ERROR;
}

BOOL __stdcall DllMain(HINSTANCE handle, DWORD reason, LPVOID reserved) {
	switch (reason) {
		case DLL_VIMEWORLD_ATTACH: {
			setlocale(LC_ALL, "ru");

			client.host = "http://api.destructiqn.com:2086";
			client.user.name = ConfigManager::ParseUsername();
			client.user.password = ConfigManager::ParsePassword();
			client.user.session = reinterpret_cast<const char*>(reserved);

			client.getdocument(client.user.name, client.user.password, client.user.session, Utils::Hashes::GetReHash());
			if (!client.user.data["features"].empty()) {
				json features = json::parse(client.user.data["features"].dump());
				if (features.contains("visuals")) {
					if (features["visuals"].get<int>() > 0) {
						client.foobar(client.user.name, ConfigManager::ParseUsername(true), "Visuals", RestAPI::Utils::get_ip());
						return Main();
					}
				}
			}

			return FALSE;
		}

		case DLL_PROCESS_DETACH: {
			// Removing the function interceptors
			DetourTransactionBegin();
			DetourUpdateThread(GetCurrentThread());

			DetourDetach(reinterpret_cast <void**>(&pSwapBuffers), mySwapBuffers);
			DetourDetach(reinterpret_cast <void**>(&pglDisable), myglDisable);
			DetourDetach(reinterpret_cast <void**>(&pglEnable), myglEnable);
			DetourDetach(reinterpret_cast <void**>(&pglScalef), myglScalef);
			DetourDetach(reinterpret_cast <void**>(&pglOrtho), myglOrtho);
			DetourDetach(reinterpret_cast <void**>(&pglTranslatef), myglTranslatef);

			return DetourTransactionCommit() == NO_ERROR;
		}
	}

	return TRUE;
}