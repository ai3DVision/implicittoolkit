#ifndef OPENGL_3D_SPHERE_RENDERER_H
#define OPENGL_3D_SPHERE_RENDERER_H

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glu.h>
#endif

#include <Eigen/Core>

class OpenGL3DSphereRenderer final
{

public:

  OpenGL3DSphereRenderer( const unsigned num_subdivs = 0 );

  void drawVertexArray( const Eigen::Matrix<GLfloat,3,1>& primary_color, const Eigen::Matrix<GLfloat,3,1>& secondary_color ) const;
  void drawVertices() const;

private:

  // Allocates memory for the vertex arrays with vertices and normals
  void allocateSphereMemory( const unsigned num_subdivs );

  // Saves the current triangle in the vertex array
  void saveTriangleInMem( const Eigen::Matrix<GLfloat,3,1>& v1, const Eigen::Matrix<GLfloat,3,1>& v2, const Eigen::Matrix<GLfloat,3,1>& v3, unsigned& current_vertex );

  // Recursive routine to refine the mesh
  void subdivide( const Eigen::Matrix<GLfloat,3,1>& v1, const Eigen::Matrix<GLfloat,3,1>& v2, const Eigen::Matrix<GLfloat,3,1>& v3, unsigned& current_vertex, const unsigned depth );

  // Builds vertex arrays with the sphere's vertices and normals
  void generateSphere( const unsigned num_subdivs );

  Eigen::Matrix<GLfloat,3,Eigen::Dynamic,Eigen::ColMajor> m_sphere_verts;
  Eigen::Matrix<GLfloat,3,Eigen::Dynamic,Eigen::ColMajor> m_sphere_normals;
  
};

#endif
