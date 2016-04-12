// Hello_Triangle.c
//
//    This is a simple example that draws a single triangle with
//    a minimal vertex/fragment shader.  

#include <stdlib.h>
#include <esUtil.h>

typedef struct {

	//program handle
	GLuint programObject; 

} UserData;

// Create a shader object, load the shader source, and
// compile the shader.

GLuint LoadShader(GLenum type, const char *shaderSrc){
   GLuint shader;
   GLuint compile_status;

   //Create shader object
   shader = glCreateShader(type);
  
   if(shader == 0)
      return 0;

   //Load shader src
   glShaderSource(shader,1,&shaderSrc,NULL);

   //Compile shader
   glCompileShader(shader);
   
   //Check Compile Status
   glGetShaderiv(shader,GL_COMPILE_STATUS,&compile_status);

   if(compile_status == 0){
      
      GLint LogLen=0;
      glGetShaderiv(shader,GL_INFO_LOG_LENGTH,&LogLen);
   
      if(LogLen > 1){
         char *Log = malloc(sizeof(char)*LogLen);
         glGetShaderInfoLog(shader,LogLen,NULL,Log);
	 esLogMessage("Error compiling shader:\n%s\n",Log);
         free(Log);
      }

      glDeleteShader(shader);
      return 0;
   }
	 
    return shader;	
}

// Initialize the shader and program object
int Init(ESContext *esContext){
   esContext->userData = malloc(sizeof(UserData));

   UserData *userData = esContext->userData;
   
   GLbyte vShaderStr[] = 
      "attribute vec3 vPosition; \n"
      "void main()               \n"
      "{                         \n"
      "  gl_Position = vec4(vPosition,1.0); \n"
      "}                         \n";
      
      
   GLbyte fShaderStr[] = 
       "precision mediump float;\n"\
       "void main()                              \n"
       "{                                        \n"
       "   gl_FragColor = vec4(1.0,0.0,0.0,1.0); \n"
       "}                                        \n";
   
   GLuint vertexShader;
   GLuint fragmentShader;
   GLuint programObject;
   GLint link_status;

   //Load vertex and fragment shaders
   vertexShader = LoadShader(GL_VERTEX_SHADER,vShaderStr);
   fragmentShader = LoadShader(GL_FRAGMENT_SHADER,fShaderStr);
   
   //Create program Object
   programObject = glCreateProgram();

   if(programObject == 0)
      return 0;

   //Attach shader to the program
   glAttachShader(programObject , vertexShader);
   glAttachShader(programObject , fragmentShader);

   //Bind attributes
   glBindAttribLocation(programObject,0,"vPosition");

   //Link the program
   glLinkProgram(programObject);
  
   //Check the link status
   glGetProgramiv(programObject,GL_LINK_STATUS,&link_status);  
   
   if(link_status == 0){
      GLint LogLen = 0;
      glGetProgramiv(programObject,GL_INFO_LOG_LENGTH,&LogLen);
      if(LogLen > 1){
         char* Log = malloc(sizeof(char)*LogLen);
         glGetProgramInfoLog(programObject,LogLen,NULL,Log);
         esLogMessage("Error linking program:\n%s\n",Log);

         free(Log);
      }

      glDeleteProgram(programObject);
      return GL_FALSE;      
    }

   //Store Program Object
   userData->programObject = programObject;

   glClearColor(1.0f,1.0f,1.0f,1.0f);
   return GL_TRUE;

}

//Draw Function
void Draw(ESContext *esContext)
{
   UserData *userData = esContext->userData;
   GLfloat vertices[] =  {  0.0f,  0.0f,  0.0f,
                           -0.8f,  0.0f,  0.0f,
			   -0.4f,  0.8f,  0.0f,
			    0.4f,  0.8f,  0.0f, 
                            0.8f,  0.0f,  0.0f,
                            0.4f, -0.8f,  0.0f,
                           -0.4f, -0.8f,  0.0f,
                           -0.8f,  0.0f,  0.0f};  
  GLushort indices[] = {0,1,2,0,2,3,0,3,4,0,4,5,0,5,6,0,6,1}; 

   //set ViewPort
   glViewport(0,0,esContext->width,esContext->height);

   //Clear the color buffer
   glClear(GL_COLOR_BUFFER_BIT);

   //Use the program object
   glUseProgram(userData->programObject);

   //Load vertex data
   glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,vertices);
   glEnableVertexAttribArray(0);

   glDrawElements(GL_TRIANGLES,18,GL_UNSIGNED_SHORT,indices);


}

int main(){
   
   ESContext esContext;
   UserData  userData;
   
   esInitContext(&esContext);
   esContext.userData = &userData;

   esCreateWindow(&esContext,"Shape using TriangleFan",640,480,ES_WINDOW_RGB);

   if(!Init(&esContext))
      return 0;
 
   esRegisterDrawFunc(&esContext,Draw);
	
   esMainLoop(&esContext);

}
