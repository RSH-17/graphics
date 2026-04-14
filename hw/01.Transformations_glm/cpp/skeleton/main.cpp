#include <iostream>

// include glm
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void glm_vec_test();
void glm_mat_test();
void glm_transform_test();

std::ostream& operator<< (std::ostream&, const glm::mat4);
std::ostream& operator<< (std::ostream&, const glm::vec3);
std::ostream& operator<< (std::ostream&, const glm::vec4);

int main()
{
  glm_vec_test();
  glm_mat_test();
  glm_transform_test();

  return  0;
}

void glm_vec_test() {
  std::cout << "---------------" << std::endl;
  std::cout << "glm vector test" << std::endl;
  std::cout << "---------------" << std::endl;
  
  glm::vec3 x;
  glm::vec3 y;
  glm::vec3 z;
  float dot;

  //////////////////////////////////////////////////////////////////////////////////////////////////
  
  // TODO 1) x = (3, 5, 7) 벡터를 생성한다.
  x = glm::vec3(3, 5, 7);

  std::cout << "x = " << x << std::endl; 

  //////////////////////////////////////////////////////////////////////////////////////////////////

  // TODO 2) x와 같은 벡터 y를 생성한다.
  y = x; // GLM은 값 복사이다.

  std::cout << "y = " << y << std::endl; 

  //////////////////////////////////////////////////////////////////////////////////////////////////

  // TODO 3) y = x + y를 수행한다.
  y = x + y;

  std::cout << "y += x" << std::endl;
  std::cout << "y => " << y << std::endl;
  std::cout << "x => " << x << std::endl;

  //////////////////////////////////////////////////////////////////////////////////////////////////

  // TODO 4) x, y 두 벡터 간의 dot product를 계산한다.
  dot = glm::dot(x, y);

  std::cout << "dot(x,y) => " << dot << std::endl;

  //////////////////////////////////////////////////////////////////////////////////////////////////

  // TODO 5) x = (1,0,0), y = (0,1,0)으로 재설정하고, 두 벡터 간의 cross product로 z를 생성한다.
  x = glm::vec3(1, 0, 0); // stack에서 값 복사 후, 삭제해서 메모리 낭비 없음
  y = glm::vec3(0, 1, 0);
  z = glm::cross(x, y);

  std::cout << "reset x as [1, 0, 0]" << std::endl;
  std::cout << "reset y as [0, 1, 0]" << std::endl;
  std::cout << "z = cross(x, y)" << std::endl;
  std::cout << "z = " << z << std::endl;
}

void glm_mat_test() {
  std::cout << std::endl;
  std::cout << "---------------" << std::endl;
  std::cout << "glm matrix test" << std::endl;
  std::cout << "---------------" << std::endl;

  glm::mat4 A;
  glm::mat4 B;

  //////////////////////////////////////////////////////////////////////////////////////////////////

  // TODO 6) construct identity matrix
  // TODO 6) 4*4 identity matrix A를 생성한다.
  A = glm::mat4(1.0f);

  std::cout << A << std::endl;

  //////////////////////////////////////////////////////////////////////////////////////////////////

  // TODO 7) A를 가음과 같은 행렬이 되도록 변경한다. 
  // [ 1 2 3 0 / 2 1 -2 0 / -1 0 1 0 / -1 2 4 1 ] <- 열우선
  // Notice: The matrix is column major
  A[0] = glm::vec4(1, 2, 3, 0); // 각각이 행이 아니라 열임
  A[1] = glm::vec4(2, 1, -2, 0);
  A[2] = glm::vec4(-1, 0, 1, 0);
  A[3] = glm::vec4(-1, 2, 4, 1);

  std::cout << "A = " << std::endl;
  std::cout << A << std::endl;  

  //////////////////////////////////////////////////////////////////////////////////////////////////

  // TODO 8) A의 전치행렬인 B 행렬을 생성한다.
  B = glm::transpose(A);

  std::cout << "B = A^T" << std::endl;
  std::cout << "B = " << std::endl;
  std::cout << B << std::endl;

  // x축, y축, z축, 원점
  glm::vec4 x(1.0f, 0.0f, 0.0f, 0.0f);
  glm::vec4 y(0.0f, 1.0f, 0.0f, 0.0f);
  glm::vec4 z(0.0f, 0.0f, 1.0f, 0.0f);
  glm::vec4 w(0.0f, 0.0f, 0.0f, 1.0f);

  std::cout << "A*x = " << A * x << std::endl;
  std::cout << "A*y = " << A * y << std::endl;
  std::cout << "A*z = " << A * z << std::endl;
  std::cout << "A*w = " << A * w << std::endl;

  std::cout << "x*A = " << x * A << std::endl;
  std::cout << "y*A = " << y * A << std::endl;
  std::cout << "z*A = " << z * A << std::endl;
  std::cout << "w*A = " << w * A << std::endl;
}

void glm_transform_test() {
  std::cout << std::endl;
  std::cout << "------------------" << std::endl;
  std::cout << "glm transform test" << std::endl;
  std::cout << "------------------" << std::endl;

  glm::mat4 mat_Translate;
  glm::mat4 mat_Scale;
  glm::mat4 mat_Rotate;
  glm::mat4 mat_LookAt;
  glm::mat4 mat_Ortho;
  glm::mat4 mat_Frustum;
  glm::mat4 mat_Perspective;
  
  // TODO 9) 다음의 조건을 만족시키는 변환행렬을 완성한다.
  /*
  - (1,-1,2)로 이동변환을 수행하는 행렬
  - (1,2,-1)을 회전축으로 하여 90도 회전변환을 수행하는 행렬
  - x, y, z축으로 각각 2, 1, 1.5 만큼 크기를 변화시키는 행렬
  - 카메라가 (0,0,-5)위치에 있고 카메라의 up-vector가 (0,1,0)일 때, (0,0,0)위치를 바라보도록 시점을 변환하는 행렬
  - 아래의 파라미터를 가지는 직교투영 행렬 (left:1, right:-1, bottom:1, top:-1, z-near:1, z-far:-1)
  - 아래의 파라미터를 가지는 절두체 행렬 (left:-0.1, right:0.1, bottom:-0.1, top:0.1, near:0.1, far:1000)
  - 시야각 60도, 0.001 10000사이의에 있는 물체를 그리기 위한원근 투영행렬, 이 때 aspect 값은 1.0이다.
  */

  // 계산용 단위행렬 생성
  glm::mat4 mat_identity(1.0f);

  // (1,-1,2)로 이동변환을 수행하는 행렬
  glm::vec3 translation(1.0f, -1.0f, 2.0f);
  mat_Translate = glm::translate(mat_identity, translation);

  // (1,2,-1)을 회전축으로 하여 90도 회전변환을 수행하는 행렬
  glm::vec3 rotation(1.0f, 2.0f, -1.0f);
  float angle_radian = glm::radians(90.0f);
  mat_Rotate = glm::rotate(mat_identity, angle_radian, rotation);
  // mat_Rotate = glm::rotate(mat_identity, angle_radian, glm::normalize(rotation));

  // x, y, z축으로 각각 2, 1, 1.5 만큼 크기를 변화시키는 행렬
  glm::vec3 scaler(2.0f, 1.0f, 1.5f);
  mat_Scale = glm::scale(mat_identity, scaler);

  // 카메라가 (0,0,-5)위치에 있고 카메라의 up-vector가 (0,1,0)일 때, (0,0,0)위치를 바라보도록 시점을 변환하는 행렬
  glm::vec3 eye(0.0f, 0.0f, -5.0f);
  glm::vec3 center(0.0f, 0.0f, 0.0f);
  glm::vec3 up_vec(0.0f, 1.0f, 0.0f);
  mat_LookAt = glm::lookAt(eye, center, up_vec);

  // 아래의 파라미터를 가지는 직교투영 행렬 (left:1, right:-1, bottom:1, top:-1, z-near:1, z-far:-1)
  mat_Ortho = glm::ortho(1.0f, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f);

  // 아래의 파라미터를 가지는 절두체 행렬 (left:-0.1, right:0.1, bottom:-0.1, top:0.1, near:0.1, far:1000)
  // 절두체 : 꼭대기가 잘려나간 사각뿔 모양 (near ----------- far)
  mat_Frustum = glm::frustum(-0.1f, 0.1f, -0.1f, 0.1f, 0.1f, 1000.0f);


  // 시야각 60도, 0.001 10000사이의에 있는 물체를 그리기 위한원근 투영행렬, 이 때 aspect 값은 1.0이다.
  mat_Perspective = glm::perspective(
    glm::radians(60.0f),  // FOV
    1.0f,                 // aspect
    0.001f,               // near
    10000.0f              // far
  );

  // DO NOT EDIT below this line
  std::cout << "Translation matrix" << std::endl;
  std::cout << mat_Translate << std::endl;

  std::cout << "Rotation matrix" << std::endl;
  std::cout << mat_Rotate << std::endl;

  std::cout << "Scaling matrix" << std::endl;
  std::cout << mat_Scale << std::endl;

  std::cout << "View matrix with lookAt()" << std::endl;
  std::cout << mat_LookAt << std::endl;

  std::cout << "Projection matrix with ortho()" << std::endl;
  std::cout << mat_Ortho << std::endl;

  std::cout << "Projection matrix with frusutm()" << std::endl;
  std::cout << mat_Frustum << std::endl;

  std::cout << "Projection matrix with perspective()" << std::endl;
  std::cout << mat_Perspective << std::endl;

}

// DO NOT EDIT below this line
std::ostream& operator<< (std::ostream& os, const glm::vec3 v) {
  os << "[";
  os << v.x << ", " << v.y << ", " << v.z;
  os << "]";
  
  return os;
}
std::ostream& operator<< (std::ostream& os, const glm::vec4 v) {
  os << "[";
  os << v.x << ", " << v.y << ", " << v.z << ", " << v.w;
  os << "]";
  
  return os;
}
std::ostream& operator<< (std::ostream& os, const glm::mat4 m) {
  os << "[" << m[0][0] << ", " << m[1][0] << ", " << m[2][0] << ", " << m[3][0] << "]" << std::endl;
  os << "[" << m[0][1] << ", " << m[1][1] << ", " << m[2][1] << ", " << m[3][1] << "]" << std::endl;
  os << "[" << m[0][2] << ", " << m[1][2] << ", " << m[2][2] << ", " << m[3][2] << "]" << std::endl;
  os << "[" << m[0][3] << ", " << m[1][3] << ", " << m[2][3] << ", " << m[3][3] << "]" << std::endl;
  
  return os;
}
