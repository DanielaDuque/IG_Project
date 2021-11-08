#include <Viewer.hpp>
#include <ShaderProgram.hpp>

#include <texturing/TexturedPlaneRenderable.hpp>
#include <texturing/TexturedCubeRenderable.hpp>
#include <texturing/MultiTexturedCubeRenderable.hpp>
#include <texturing/MipMapCubeRenderable.hpp>
#include <texturing/BillBoardPlaneRenderable.hpp>

#include <lighting/DirectionalLightRenderable.hpp>
#include <lighting/Material.hpp>
#include <lighting/LightedCylinderRenderable.hpp>
#include <lighting/DirectionalLightRenderable.hpp>
#include <lighting/LightedMeshRenderable.hpp>
#include <lighting/PointLightRenderable.hpp>

#include <texturing/TexturedTriangleRenderable.hpp>
#include <GeometricTransformation.hpp>
#include <FrameRenderable.hpp>
#include <texturing/TexturedLightedMeshRenderable.hpp>

#include <HierarchicalMeshRenderable.hpp>


#include <string>

#include <iostream>
using std::string;

void movingSeahorse(float initialTime, 
                    Viewer& viewer, ShaderProgramPtr flatShader, 
                    glm::vec3 initial_pos, float duration
                    ){

    MaterialPtr bronze = Material::Bronze();
    LightedMeshRenderablePtr seahorse = std::make_shared<LightedMeshRenderable>(flatShader, "./../../sfmlGraphicsPipeline/meshes/seahorse.obj");
    seahorse->setMaterial(bronze);

/*     glm::mat4 LocalTransform = glm::mat4(1);
    LocalTransform = glm::translate(LocalTransform, initial_pos);
    seahorse->setLocalTransform(LocalTransform); */

    seahorse->addParentTransformKeyframe(GeometricTransformation( initial_pos,  glm::quat{1,0,0,0}, 
                                                            glm::vec3(2,2,2)),0); 

        // Moving of submarine
    int x_pos = -25;
    int y_pos = -10;
    glm::vec3 pos;


    for (float i = initialTime; i < duration + initialTime; i++)
    {
        pos = initial_pos + glm::vec3(x_pos, y_pos, 0);
        if((int)i%2==0){
            seahorse->addParentTransformKeyframe(GeometricTransformation( pos,  glm::quat{1,0,0,0}, 
                                                            glm::vec3(3,3,3)),i); 
            y_pos +=4;                                                       
        }else{
            seahorse->addParentTransformKeyframe(GeometricTransformation( pos, glm::quat{1,0,0,0}, 
                                                            glm::vec3(3,3,3)),i);
            y_pos -=3.7;
        }
        x_pos +=2;
    }
	// Add the renderable to the Viewer
	viewer.addRenderable ( seahorse );        
 }

 void movingSubmarine(LightedMeshRenderablePtr submarine, float initialTime, glm::vec3 initialPos, float duration){
    int x_pos = -30;
    int y_pos = -15;
    glm::vec3 pos;
    for (int i = 0; i < duration; i++)
    {
        pos = initialPos + glm::vec3(x_pos, y_pos, 0);
        if(i%2==0){
            submarine->addParentTransformKeyframe(GeometricTransformation( pos, glm::angleAxis(-3.14f / 2, glm::vec3(0.0,1.0,0)), 
                                                            glm::vec3(1,1,1)),i+initialTime); 
            y_pos +=5;                                                       
        }else{
            submarine->addParentTransformKeyframe(GeometricTransformation( pos, glm::angleAxis(-3.14f / 2, glm::vec3(0.0,1.0,0.0)), 
                                                            glm::vec3(1,1,1)),i+ initialTime);
            y_pos -=3;
        }
        x_pos +=3;
    }

 }

 void movingAletas (LightedMeshRenderablePtr aletas, float initialTime, float duration){

      for (int i = 0; i < duration; i++)
    {   
        aletas->addParentTransformKeyframe(GeometricTransformation(glm::vec3(), glm::quat{1,0,0,0}, 
                                                            glm::vec3(1,1,1)), i + initialTime);

        aletas->addParentTransformKeyframe(GeometricTransformation( glm::vec3(-1.8,0.55,0), glm::angleAxis(-3.14f/4, glm::vec3(0.0,0.0,1.0)), 
                                                                glm::vec3(1,1,1)), 0.25+i + initialTime); 
        
        aletas->addParentTransformKeyframe(GeometricTransformation(glm::vec3(0.0,0.0,0.0), glm::quat{1,0,0,0}, 
                                                                glm::vec3(1,1,1)), 0.5+i + initialTime); 
        
        aletas->addParentTransformKeyframe(GeometricTransformation(glm::vec3(1.8,0.55,0.0), glm::angleAxis(3.14f/4, glm::vec3(0.0,0.0,1.0)), 
                                                            glm::vec3(1,1,1)), 0.75+i +initialTime);                                                           
    }  
 }
 
void movingVisor(LightedMeshRenderablePtr visor, float initialTime, float duration){

    for (int i = 0; i < duration ; i +=2)
    {   
        visor->addParentTransformKeyframe(GeometricTransformation(glm::vec3(), glm::quat{1,0,0,0}, 
                                                            glm::vec3(1,1,1)), i + initialTime);

        visor->addParentTransformKeyframe(GeometricTransformation( glm::vec3(-1.0,0.0,0), glm::angleAxis(-3.14f/4, glm::vec3(0.0,1.0,0.0)), 
                                                                glm::vec3(1,1,1)), 0.55+i + initialTime); 
        
        visor->addParentTransformKeyframe(GeometricTransformation(glm::vec3(0.0,0.0,0.0), glm::quat{1,0,0,0}, 
                                                                glm::vec3(1,1,1)), 1+i + initialTime); 
        
        visor->addParentTransformKeyframe(GeometricTransformation(glm::vec3(1.0,0.0,0.0), glm::angleAxis(3.14f/4, glm::vec3(0.0,1.0,0.0)), 
                                                            glm::vec3(1,1,1)), 1.5+i +initialTime);                                                           
    }  
}
// -------------------------------- Scenes -------------------------------------------------------------

void Scene1 (Viewer& viewer, LightedMeshRenderablePtr submarine, LightedMeshRenderablePtr aletas){

    // Moving of submarine
    movingSubmarine( submarine, 0, glm::vec3(0),21);

    // Moving Aletas    
    movingAletas (aletas, 0,21);
   
}


void Scene2 (Viewer& viewer, ShaderProgramPtr flatShader){
        string caballito = "../../sfmlGraphicsPipeline/meshes/seahorse.obj";
        glm::vec3 traslation = glm::vec3(30, 10,-0);
        movingSeahorse(21, viewer, flatShader, glm::vec3(-55 , -40, -20 ) ,25);
        movingSeahorse(21.1, viewer, flatShader, glm::vec3(-55 , -30, -10 ) ,25);
        movingSeahorse(21.2, viewer, flatShader, glm::vec3(-60 , -40, -10 ) , 25);
        movingSeahorse(21.3, viewer, flatShader, glm::vec3(-60 , -30, -20 ) ,25);
        movingSeahorse(21.4, viewer, flatShader, glm::vec3(-65 , -40, -20 ) ,25);
        movingSeahorse(21.5, viewer, flatShader, glm::vec3(-65 , -30, -10 ) ,25);
        movingSeahorse(21.6, viewer, flatShader, glm::vec3(-70 , -40, -10 ) ,25);
        movingSeahorse(21.7, viewer, flatShader, glm::vec3(-70 , -30, -20 ) ,25);
        movingSeahorse(21.8, viewer, flatShader, glm::vec3(-75 , -40, -20 ) ,25);
        movingSeahorse(21.9, viewer, flatShader, glm::vec3(-75 , -30, -10 ) ,25);
}

void Scene3 (Viewer& viewer, ShaderProgramPtr flatShader,  
            LightedMeshRenderablePtr submarine, LightedMeshRenderablePtr aletas,
            LightedMeshRenderablePtr visor ){

        // Sea Horse
        glm::vec3 traslation = glm::vec3(30, 10,-0);
        movingSeahorse(45, viewer, flatShader, glm::vec3(55 , -40, -20 ) ,27);
        movingSeahorse(45.1, viewer, flatShader, glm::vec3(55 , -30, 0 ) ,27);
        movingSeahorse(45.2, viewer, flatShader, glm::vec3(60 , -40, 0 ) ,27);
        movingSeahorse(45.3, viewer, flatShader, glm::vec3(60 , -30, -20 ) ,27);
        movingSeahorse(45.4, viewer, flatShader, glm::vec3(65 , -40, -20 ) ,27);
        movingSeahorse(45.5, viewer, flatShader, glm::vec3(65 , -30, 0 ) ,27);
        movingSeahorse(45.6, viewer, flatShader, glm::vec3(70 , -40, 0 ) ,27);
        movingSeahorse(45.7, viewer, flatShader, glm::vec3(70 , -30, -20 ) ,27);
        movingSeahorse(45.8, viewer, flatShader, glm::vec3(75 , -40, -20 ) ,27);
        movingSeahorse(45.9, viewer, flatShader, glm::vec3(75 , -30, 0 ) ,27);

        // Submarine
            // Moving of submarine
        submarine->addParentTransformKeyframe(GeometricTransformation( glm::vec3(50 , -45, -10 ), glm::angleAxis(-3.14f / 2, glm::vec3(0.0,1.0,0)), 
                                                            glm::vec3(1,1,1)),25);
        movingSubmarine( submarine, 45, glm::vec3(50 , -45, -10 ),27);
            // Moving Aletas    
        movingAletas (aletas, 45,25);
            //Moving Visor
        movingVisor(visor,45,25);
}

 
LightedMeshRenderablePtr* createSubmarine(Viewer& viewer, ShaderProgramPtr flatShader){
    MaterialPtr silver = Material::Silver();
    MaterialPtr pearl = Material::Pearl();
    MaterialPtr emerald = Material::Emerald();
    MaterialPtr bronze = Material::Bronze();
    MaterialPtr turquoise = Material::Turquoise();
    MaterialPtr whiteRubber = Material::WhiteRubber();
    MaterialPtr yellowRubber = Material::YellowRubber();
    MaterialPtr gold = Material::Gold();
    MaterialPtr ruby = Material::Ruby();
    MaterialPtr green = Material::Green();


    LightedMeshRenderablePtr* subamrineGroup= new LightedMeshRenderablePtr[10];

    // Cuerpo
    subamrineGroup[0] = std::make_shared<LightedMeshRenderable>(flatShader, "./../../sfmlGraphicsPipeline/meshes/cuerpo.obj");
    subamrineGroup[0]->setMaterial(silver);

    // Aletas
     subamrineGroup[1] = std::make_shared<LightedMeshRenderable>(flatShader, "./../../sfmlGraphicsPipeline/meshes/aletas.obj");
    subamrineGroup[1]->setMaterial(ruby);

    // Visor
     subamrineGroup[2] = std::make_shared<LightedMeshRenderable>(flatShader, "./../../sfmlGraphicsPipeline/meshes/visor.obj");
    subamrineGroup[2]->setMaterial(bronze);

    // Cola
     subamrineGroup[3] = std::make_shared<LightedMeshRenderable>(flatShader, "./../../sfmlGraphicsPipeline/meshes/cola.obj");
    subamrineGroup[3]->setMaterial(yellowRubber);

    // Ventana Lateral
     subamrineGroup[4] = std::make_shared<LightedMeshRenderable>(flatShader, "./../../sfmlGraphicsPipeline/meshes/ventana_laterales.obj");
    subamrineGroup[4]->setMaterial(gold);

    // Ventana Principal
     subamrineGroup[5] = std::make_shared<LightedMeshRenderable>(flatShader, "./../../sfmlGraphicsPipeline/meshes/ventana_principal.obj");
    subamrineGroup[5]->setMaterial(gold);

    // Ventana visor
     subamrineGroup[6] = std::make_shared<LightedMeshRenderable>(flatShader, "./../../sfmlGraphicsPipeline/meshes/ventana_visor.obj");
    subamrineGroup[6]->setMaterial(gold);

    // Vidrio Lateral
     subamrineGroup[7] = std::make_shared<LightedMeshRenderable>(flatShader, "./../../sfmlGraphicsPipeline/meshes/vidrio_laterales.obj");
    subamrineGroup[7]->setMaterial(turquoise);

    // Vidio Principal
     subamrineGroup[8] = std::make_shared<LightedMeshRenderable>(flatShader, "./../../sfmlGraphicsPipeline/meshes/vidrio_principal.obj");
    subamrineGroup[8]->setMaterial(turquoise);

    // Vidrio visor
     subamrineGroup[9] = std::make_shared<LightedMeshRenderable>(flatShader, "./../../sfmlGraphicsPipeline/meshes/vidrio_visor.obj");
    subamrineGroup[9]->setMaterial(turquoise);
    

    // Children
    HierarchicalRenderable :: addChild(subamrineGroup[0], subamrineGroup[1]);
    HierarchicalRenderable :: addChild(subamrineGroup[0], subamrineGroup[2]);
    HierarchicalRenderable :: addChild(subamrineGroup[0], subamrineGroup[3]);
    HierarchicalRenderable :: addChild(subamrineGroup[0], subamrineGroup[4]);
    HierarchicalRenderable :: addChild(subamrineGroup[0], subamrineGroup[5]);
    HierarchicalRenderable :: addChild(subamrineGroup[2], subamrineGroup[6]);
    HierarchicalRenderable :: addChild(subamrineGroup[0], subamrineGroup[7]);
    HierarchicalRenderable :: addChild(subamrineGroup[0], subamrineGroup[8]);
    HierarchicalRenderable :: addChild(subamrineGroup[2], subamrineGroup[9]);


    return subamrineGroup;
    //movingSubmarine( viewer, submarine);
    
}

void movingCamera(Viewer& viewer){
    if( viewer.getTime() > 45)
    {
        viewer.getCamera().setViewMatrix( glm::lookAt(  glm::vec3( 70, -37, 20 ), 
                                                        glm::vec3(70, -37, 0), 
                                                        glm::vec3( 0, 1, 0 ) ) );
    }
    else if (viewer.getTime() > 21)
    {
     //std::cout << viewer.getTime() << std::endl;
       viewer.getCamera().setViewMatrix( glm::lookAt(   glm::vec3( -60, -40, 20 ), 
                                                        glm::vec3(-60, -40, 0), 
                                                        glm::vec3( 0, 1, 0 ) ) );
    }
    else
    {

        //std::cout << viewer.getTime() << std::endl;
        const float radius = 30.0f;
        float camZ = std::min ( 20.0, cos(viewer.getTime()) * radius );
        viewer.getCamera().setViewMatrix( glm::lookAt(  glm::vec3( 0, 0, 20 ), 
                                                        glm::vec3( 0, 0, 0), 
                                                        glm::vec3( 0, 1, 0 ) ) );
    }
}

void initialize_scene( Viewer& viewer )
{
      

    ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(  "../../sfmlGraphicsPipeline/shaders/flatVertex.glsl",
                                                                    "../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");
    viewer.addShaderProgram( flatShader );

    ShaderProgramPtr phongShader = std::make_shared<ShaderProgram>( "../../sfmlGraphicsPipeline/shaders/phongVertex.glsl", 
                                                                    "../../sfmlGraphicsPipeline/shaders/phongFragment.glsl");
    viewer.addShaderProgram( phongShader );


    //Add a 3D frame to the viewer
    FrameRenderablePtr frame = std::make_shared<FrameRenderable>(flatShader);
    viewer.addRenderable(frame);




    //Temporary variables
    glm::mat4 parentTransformation(1.0), localTransformation(1.0);

    // Adding submarine

    LightedMeshRenderablePtr* submarineGroup = new LightedMeshRenderablePtr[10];
    submarineGroup = createSubmarine(viewer,  phongShader);
    for (int i = 0; i < 10; i++)
    {
        viewer.addRenderable( submarineGroup[i] );
    }

    // ------------- Scenes -----------
    Scene1( viewer, submarineGroup[0], submarineGroup[1]);
    Scene2 ( viewer, phongShader);
    Scene3 ( viewer,  phongShader, submarineGroup[0],  submarineGroup[1], submarineGroup[2] );
    

//Define a directional light for the whole scene
    glm::vec3 d_direction = glm::normalize(glm::vec3(0.0,-1.0,-1.0));
    glm::vec3 d_ambient(0.0,0.0,0.0), d_diffuse(0.3,0.3,0.1), d_specular(0.3,0.3,0.1);
    //glm::vec3 d_ambient(0.0,0.0,0.0), d_diffuse(0.0,0.0,0.0), d_specular(0.0,0.0,0.0);
    DirectionalLightPtr directionalLight = std::make_shared<DirectionalLight>(d_direction, d_ambient, d_diffuse, d_specular);
    //Add a renderable to display the light and control it via mouse/key event
    glm::vec3 lightPosition(0.0,5.0,8.0);
    DirectionalLightRenderablePtr directionalLightRenderable = std::make_shared<DirectionalLightRenderable>(flatShader, directionalLight, lightPosition);
    localTransformation = glm::scale(glm::mat4(1.0), glm::vec3(0.5,0.5,0.5));
    directionalLightRenderable->setLocalTransform(localTransformation);
    viewer.setDirectionalLight(directionalLight);
    viewer.addRenderable(directionalLightRenderable);

    //Define a point light
    glm::vec3 p_position(0.0,0.0,0.0), p_ambient(0.0,0.0,0.0), p_diffuse(0.0,0.0,0.0), p_specular(0.0,0.0,0.0);
    float p_constant=0.0, p_linear=0.0, p_quadratic=0.0;

    p_position = glm::vec3(-8, 5.0, 5.0);
    p_ambient = glm::vec3(0.0,0.0,0.0);
    p_diffuse = glm::vec3(1.0,0.0,0.0);
    p_specular = glm::vec3(1.0,0.0,0.0);
    p_constant=1.0;
    p_linear=5e-1;
    p_quadratic=0;
    PointLightPtr pointLight1 = std::make_shared<PointLight>(p_position, p_ambient, p_diffuse, p_specular, p_constant, p_linear, p_quadratic);
    PointLightRenderablePtr pointLightRenderable1 = std::make_shared<PointLightRenderable>(flatShader, pointLight1);
    localTransformation = glm::scale(glm::mat4(1.0), glm::vec3(0.5,0.5,0.5));
    pointLightRenderable1->setLocalTransform(localTransformation);
    viewer.addPointLight(pointLight1);
    viewer.addRenderable(pointLightRenderable1);

    p_position = glm::vec3(8, 5.0, 5.0);
    p_ambient = glm::vec3(0.0,0.0,0.0);
    p_diffuse = glm::vec3(0.0,0.0,1.0);
    p_specular = glm::vec3(0.0,0.0,1.0);
    p_constant=1.0;
    p_linear=5e-1;
    p_quadratic=0;
    PointLightPtr pointLight2 = std::make_shared<PointLight>(p_position, p_ambient, p_diffuse, p_specular, p_constant, p_linear, p_quadratic);
    PointLightRenderablePtr pointLightRenderable2 = std::make_shared<PointLightRenderable>(flatShader, pointLight2);
    localTransformation = glm::scale(glm::mat4(1.0), glm::vec3(0.5,0.5,0.5));
    pointLightRenderable2->setLocalTransform(localTransformation);
    viewer.addPointLight(pointLight2);
    viewer.addRenderable(pointLightRenderable2);



    // viewer.addRenderable(texPlane);
}

int main() 
{
	Viewer viewer(1280,720);
	initialize_scene(viewer);
    viewer.startAnimation();
     movingCamera(viewer);

	while( viewer.isRunning() )
	{
		viewer.handleEvent();
		viewer.animate();
		viewer.draw();
		viewer.display();
        movingCamera(viewer);
       
        
        
	}	

	return EXIT_SUCCESS;
}