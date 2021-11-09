#include <Viewer.hpp>
#include <ShaderProgram.hpp>

#include <glm/gtc/random.hpp>

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
#include <lighting/SpotLightRenderable.hpp> 

#include <texturing/TexturedTriangleRenderable.hpp>
#include <GeometricTransformation.hpp>
#include <FrameRenderable.hpp>
#include <texturing/TexturedLightedMeshRenderable.hpp>

#include <HierarchicalMeshRenderable.hpp>

#include <dynamics/DynamicSystem.hpp>
#include <dynamics/DynamicSystemRenderable.hpp>
#include <dynamics/ConstantForceField.hpp>
#include <dynamics/ParticleRenderable.hpp>
#include <dynamics/EulerExplicitSolver.hpp>


#include <string>

#include <iostream>
using std::string;


void createParticle(Viewer& viewer, DynamicSystemPtr& system, DynamicSystemRenderablePtr &systemRenderable,
                ShaderProgramPtr flatShader,
                 glm::vec3 pxInitial,  std::vector< glm::vec3 > pv )
{

    float pm, pr;
    int size = pv.size();
    int numParticles = 50;
    glm::vec3 px = pxInitial;
    //Particles with gravity and damping
    {
        //Initialize a particle with position, velocity, mass and radius and add it to the system
        pr = 0.3;
        pm = 1.0;
        ParticlePtr* particles = new ParticlePtr[numParticles];
        ParticleRenderablePtr* particlesRedable = new ParticleRenderablePtr[numParticles];
        for (int i = 0; i < numParticles; i++)
        {
            
  
            px = px + glm::vec3 (0,-2,0) ;//+ glm::ballRand(1.0f);
            particles[i] = std::make_shared<Particle>( px, pv[i%size], pm, pr);

            system->addParticle( particles[i]);
           
        }

        //Initialize a force field that apply to all the particles of the system to simulate gravity
        //Add it to the system as a force field
        ConstantForceFieldPtr gravityForceField = std::make_shared<ConstantForceField>(system->getParticles(), glm::vec3{0,2,0} );
        system->addForceField( gravityForceField );

        //Create a particleRenderable for each particle of the system
        //DynamicSystemRenderable act as a hierarchical renderable
        //This which allows to easily apply transformation on the visualiazation of a dynamicSystem
        
        for (int i = 0; i < numParticles; i++)
        {
            
            particlesRedable[i] = std::make_shared<ParticleRenderable>(flatShader, particles[i]);
            HierarchicalRenderable::addChild( systemRenderable, particlesRedable[i] );
        } 
    }
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
 void movingSubmarineFront(LightedMeshRenderablePtr submarine, float initialTime, 
                            glm::vec3 initialPos, float duration,
                            int xDes, float angle){
    int x_pos = 0;
    int z_pos = -20;
    int y_pos = 0;
    glm::vec3 pos;
    for (int i = 0; i < duration; i++)
    {
        pos = initialPos + glm::vec3(x_pos, y_pos, z_pos);
        if(i%2==0){
            submarine->addParentTransformKeyframe(GeometricTransformation( pos, glm::angleAxis(angle , glm::vec3(0.0,1.0,0)), 
                                                            glm::vec3(1,1,1)),i+initialTime); 
            x_pos +=5 + xDes; 
            y_pos +=5;                                                      
        }else{
            submarine->addParentTransformKeyframe(GeometricTransformation( pos, glm::angleAxis(angle , glm::vec3(0.0,1.0,0.0)), 
                                                            glm::vec3(1,1,1)),i+ initialTime);
            x_pos -=5 ;
            y_pos -=3.5;
        }
        z_pos +=1.5;
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
        visor->addParentTransformKeyframe(GeometricTransformation(glm::vec3(0.0,-0.5,0.0), glm::quat{1,0,0,0}, 
                                                            glm::vec3(1,1,1)), i + initialTime);

        visor->addParentTransformKeyframe(GeometricTransformation( glm::vec3(-1.0,-0.5,0), glm::angleAxis(-3.14f/4, glm::vec3(0.0,1.0,0.0)), 
                                                                glm::vec3(1,1,1)), 0.55+i + initialTime); 
        
        visor->addParentTransformKeyframe(GeometricTransformation(glm::vec3(0.0,-0.5,0.0), glm::quat{1,0,0,0}, 
                                                                glm::vec3(1,1,1)), 1+i + initialTime); 
        
        visor->addParentTransformKeyframe(GeometricTransformation(glm::vec3(1.0,-0.5,0.0), glm::angleAxis(3.14f/4, glm::vec3(0.0,1.0,0.0)), 
                                                            glm::vec3(1,1,1)), 1.5+i +initialTime);                                                           
    }  
}
// -------------------------------- Scenes -------------------------------------------------------------

void Scene1 (Viewer& viewer, LightedMeshRenderablePtr submarine, LightedMeshRenderablePtr aletas,
            ShaderProgramPtr flatShader ){

    

    // Moving of submarine
    movingSubmarine( submarine, 0, glm::vec3(0,0,-10),21);

    // Moving Aletas    
    movingAletas (aletas, 0,21);

    // Particle
    DynamicSystemPtr system = std::make_shared<DynamicSystem>();
    EulerExplicitSolverPtr solver = std::make_shared<EulerExplicitSolver>();
    system->setSolver(solver);
    system->setDt(0.01);
    // Activate collision detection
    system->setCollisionsDetection(true);

    //Create a renderable associated to the dynamic system
    //This renderable is responsible for calling DynamicSystem::computeSimulationStep() in the animate() function
    //It is also responsible for some of the key/mouse events
    DynamicSystemRenderablePtr systemRenderable = std::make_shared<DynamicSystemRenderable>(system);
    viewer.addRenderable(systemRenderable);

    std::vector< glm::vec3 > velDer;
    for (int i = 0; i < 15; i++)
    {
        velDer.push_back(glm::vec3(6-i/10,0,0));
    }

    std::vector< glm::vec3 > velIzq;
    for (int i = 0; i < 15; i++)
    {
        velIzq.push_back(glm::vec3(-6+i/10,0,0));
    }
    

    createParticle( viewer, system, systemRenderable, flatShader, glm::vec3(30,-60,-10), velIzq  );
    createParticle( viewer, system, systemRenderable, flatShader, glm::vec3(-20,-60,-10), velDer);

    createParticle( viewer, system, systemRenderable, flatShader, glm::vec3(20,-30,-10), velIzq  );
    createParticle( viewer, system, systemRenderable, flatShader, glm::vec3(-20,-30,-10), velDer);
    
    createParticle( viewer, system, systemRenderable, flatShader, glm::vec3(30,-40,-10), velIzq  );
    createParticle( viewer, system, systemRenderable, flatShader, glm::vec3(-20,-40,-10), velDer);

    createParticle( viewer, system, systemRenderable, flatShader, glm::vec3(30,-50,-10), velIzq  );
    createParticle( viewer, system, systemRenderable, flatShader, glm::vec3(-20,-50,-10), velDer);

    createParticle( viewer, system, systemRenderable, flatShader, glm::vec3(30,-70,-10), velIzq  );
    createParticle( viewer, system, systemRenderable, flatShader, glm::vec3(-20,-70,-10), velDer);

    // ---------------- Lights ---------------

    glm::mat4 parentTransformation, localTransformation;

    //Define a spot light 1

    glm::vec3 s_ambient(0.3,0.3,0.3), s_diffuse(0.5,0.5,0.5), s_specular(0.5,0.5,0.5);
    float s_constant=1.0, s_linear=0.0, s_quadratic=0.0;
    float s_innerCutOff=std::cos(glm::radians(20.0f)), s_outerCutOff=std::cos(glm::radians(40.0f));


    glm::vec3 s_position(-10.0,20.0,20.0), s_spotDirection = glm::normalize(glm::vec3(1.0,-1.0,-1.0));
    SpotLightPtr spotLight = std::make_shared<SpotLight>(s_position, s_spotDirection,
                                                         s_ambient, s_diffuse, s_specular,
                                                         s_constant, s_linear, s_quadratic,
                                                         s_innerCutOff, s_outerCutOff);
    SpotLightRenderablePtr spotLightRenderable = std::make_shared<SpotLightRenderable>(flatShader, spotLight);
    localTransformation = glm::scale(glm::mat4(1.0), glm::vec3(0.5,0.5,0.5));
    spotLightRenderable->setLocalTransform(localTransformation);
    viewer.addSpotLight(spotLight);
    viewer.addRenderable(spotLightRenderable);

    //Define a spot light 2
    glm::vec3 s2_position(20.0,20.0,-20.0), s2_spotDirection = glm::normalize(glm::vec3(-1.0,-1.0,1.0));
    SpotLightPtr spotLight_2 = std::make_shared<SpotLight>(s2_position, s2_spotDirection,
                                                         s_ambient, s_diffuse, s_specular,
                                                         s_constant, s_linear, s_quadratic,
                                                         s_innerCutOff, s_outerCutOff);
    SpotLightRenderablePtr spotLightRenderable_2 = std::make_shared<SpotLightRenderable>(flatShader, spotLight);
    localTransformation = glm::scale(glm::mat4(1.0), glm::vec3(0.5,0.5,0.5));
    spotLightRenderable_2->setLocalTransform(localTransformation);
    viewer.addSpotLight(spotLight_2);
    viewer.addRenderable(spotLightRenderable_2);

   
}


void Scene2 (Viewer& viewer, ShaderProgramPtr phongShader, float initialTime, float duration,
            ShaderProgramPtr flatShader){

    float time = initialTime;
    int pos_x = -175;
    for (int i = 1; i < 6; i++)
    {
        if ( i %2 == 0){
            movingSeahorse(time, viewer, phongShader, glm::vec3(pos_x + 8 , -45, -20 ) ,duration);
            movingSeahorse(time + 0.1, viewer, phongShader, glm::vec3(pos_x + 2, -37, -15 ) ,duration);
            movingSeahorse(time + 0.1, viewer, phongShader, glm::vec3(pos_x , -30, -10) ,duration);
            movingSeahorse(time + 0.1, viewer, phongShader, glm::vec3(pos_x , -23, -5 ) ,duration);
        }
        else{
            movingSeahorse(time, viewer, phongShader, glm::vec3(pos_x  , -45, -5 ) ,duration);
            movingSeahorse(time + 0.1, viewer, phongShader, glm::vec3(pos_x , -37, -10 ) ,duration);
            movingSeahorse(time + 0.1, viewer, phongShader, glm::vec3(pos_x + 2, -30, -15) ,duration);
            movingSeahorse(time + 0.1, viewer, phongShader, glm::vec3(pos_x + 8 , -23, -20 ) ,duration);
        }

        pos_x-=5;
        time+=0.2;
    }

       // ---------------- Lights ---------------

    glm::mat4 parentTransformation, localTransformation;

    //Define a spot light 1
    glm::vec3 s_position(-180.0,20.0,20.0), s_spotDirection = glm::normalize(glm::vec3(1.0,-1.0,-1.0));
    glm::vec3 s_ambient(0.3,0.3,0.3), s_diffuse(0.5,0.5,0.5), s_specular(0.5,0.5,0.5);
    float s_constant=1.0, s_linear=0.0, s_quadratic=0.0;
    float s_innerCutOff=std::cos(glm::radians(20.0f)), s_outerCutOff=std::cos(glm::radians(40.0f));
    SpotLightPtr spotLight = std::make_shared<SpotLight>(s_position, s_spotDirection,
                                                         s_ambient, s_diffuse, s_specular,
                                                         s_constant, s_linear, s_quadratic,
                                                         s_innerCutOff, s_outerCutOff);
    SpotLightRenderablePtr spotLightRenderable = std::make_shared<SpotLightRenderable>(flatShader, spotLight);
    localTransformation = glm::scale(glm::mat4(1.0), glm::vec3(0.5,0.5,0.5));
    spotLightRenderable->setLocalTransform(localTransformation);
    
    viewer.addSpotLight(spotLight);
    viewer.addRenderable(spotLightRenderable);
    
}


void Scene3 (Viewer& viewer, ShaderProgramPtr phongShader,  
            LightedMeshRenderablePtr submarine, LightedMeshRenderablePtr aletas,
            LightedMeshRenderablePtr visor,
            float initialTime, float duration,
            ShaderProgramPtr flatShader){

        // Sea Horse
        float time = initialTime;
        int pos_x = 175;
        for (int i = 0; i < 5; i++)
        {
            if ( i %2 == 0){
                movingSeahorse(time, viewer, phongShader, glm::vec3(pos_x + 8 , -45, -20 ) ,duration);
                movingSeahorse(time + 0.1, viewer, phongShader, glm::vec3(pos_x + 2, -37, -15 ) ,duration);
                movingSeahorse(time + 0.1, viewer, phongShader, glm::vec3(pos_x , -30, -5) ,duration);
                movingSeahorse(time + 0.1, viewer, phongShader, glm::vec3(pos_x , -23, 0 ) ,duration);
            }
            else{
                movingSeahorse(time, viewer, phongShader, glm::vec3(pos_x  , -45, -0 ) ,duration);
                movingSeahorse(time + 0.1, viewer, phongShader, glm::vec3(pos_x , -37, -5 ) ,duration);
                movingSeahorse(time + 0.1, viewer, phongShader, glm::vec3(pos_x + 2, -30, -15) ,duration);
                movingSeahorse(time + 0.1, viewer, phongShader, glm::vec3(pos_x + 8 , -23, -20 ) ,duration);
            }

            pos_x-=5;
            time+=0.2;
    }


    // Submarine
        // Moving of submarine
    submarine->addParentTransformKeyframe(GeometricTransformation( glm::vec3(152 , -45, -10 ), glm::angleAxis(-3.14f / 2, glm::vec3(0.0,1.0,0)), 
                                                        glm::vec3(1,1,1)),initialTime-10);
    movingSubmarine( submarine, initialTime, glm::vec3(152 , -45, -10 ),duration);
        // Moving Aletas    
    movingAletas (aletas, initialTime,duration);
        //Moving Visor
    movingVisor(visor,initialTime,duration);

    // ---------------- Lights ---------------

    glm::mat4 parentTransformation, localTransformation;

    //Define a spot light 1
    glm::vec3 s_position(175.0,30.0,10.0), s_spotDirection = glm::normalize(glm::vec3(-1.0,-1.0,-1.0));
    glm::vec3 s_ambient(0.3,0.3,0.3), s_diffuse(0.5,0.5,0.5), s_specular(0.5,0.5,0.5);
    float s_constant=1.0, s_linear=0.0, s_quadratic=0.0;
    float s_innerCutOff=std::cos(glm::radians(20.0f)), s_outerCutOff=std::cos(glm::radians(40.0f));
    SpotLightPtr spotLight = std::make_shared<SpotLight>(s_position, s_spotDirection,
                                                         s_ambient, s_diffuse, s_specular,
                                                         s_constant, s_linear, s_quadratic,
                                                         s_innerCutOff, s_outerCutOff);
    SpotLightRenderablePtr spotLightRenderable = std::make_shared<SpotLightRenderable>(flatShader, spotLight);
    localTransformation = glm::scale(glm::mat4(1.0), glm::vec3(3.5,3.5,3.5));
    spotLightRenderable->setLocalTransform(localTransformation);

    HierarchicalRenderable :: addChild(visor, spotLightRenderable);               
    viewer.addSpotLight(spotLight);
    viewer.addRenderable(spotLightRenderable);
        
}

void Scene4 (Viewer& viewer, ShaderProgramPtr phongShader,  
            LightedMeshRenderablePtr submarine, LightedMeshRenderablePtr aletas,
            LightedMeshRenderablePtr visor,
            float initialTime, float duration,
            ShaderProgramPtr flatShader  ){

    
    //newSubamire

    LightedMeshRenderablePtr* submarineGroup = new LightedMeshRenderablePtr[10];
    submarineGroup = createSubmarine(viewer,  phongShader);
    for (int i = 0; i < 10; i++)
    {
        viewer.addRenderable( submarineGroup[i] );
    }

    submarineGroup[0]->addParentTransformKeyframe(GeometricTransformation( glm::vec3(-30 , -120, -10 ), glm::angleAxis(-3.14f, glm::vec3(0.0,1.0,0)), 
                                                        glm::vec3(1,1,1)),initialTime-0.1);
    movingSubmarineFront( submarineGroup[0], initialTime, glm::vec3(-30 , -120, -10 ),duration, 2.8, 5* 3.14/4);
        // Moving Aletas    
    movingAletas (submarineGroup[1], initialTime,duration);
        //Moving Visor
    movingVisor(submarineGroup[2],initialTime,duration);
    
    // Submarine
        // Moving of submarine
    submarine->addParentTransformKeyframe(GeometricTransformation( glm::vec3(30 , -120, -10 ), glm::angleAxis(-3.14f, glm::vec3(0.0,1.0,0)), 
                                                        glm::vec3(1,1,1)),initialTime-0.1);
    movingSubmarineFront( submarine, initialTime, glm::vec3(30 , -120, -10 ),duration, -2.8, 3 * 3.14/4);
        // Moving Aletas    
    movingAletas (aletas, initialTime,duration);
        //Moving Visor
    movingVisor(visor,initialTime,duration);

    // ---------------- Lights ---------------

    glm::mat4 parentTransformation, localTransformation;

    glm::vec3 s_ambient(0.4,0.4,0.4), s_diffuse(0.5,0.5,0.5), s_specular(0.5,0.5,0.5);
    float s_constant=1.0, s_linear=0.0, s_quadratic=0.0;
    float s_innerCutOff=std::cos(glm::radians(20.0f)), s_outerCutOff=std::cos(glm::radians(40.0f));
    //Define a spot light 1
    glm::vec3 s_position(-10.0,-60.0,20.0), s_spotDirection = glm::normalize(glm::vec3(1.0,-1.0,-1.0));


    SpotLightPtr spotLight = std::make_shared<SpotLight>(s_position, s_spotDirection,
                                                         s_ambient, s_diffuse, s_specular,
                                                         s_constant, s_linear, s_quadratic,
                                                         s_innerCutOff, s_outerCutOff);
    SpotLightRenderablePtr spotLightRenderable = std::make_shared<SpotLightRenderable>(flatShader, spotLight);
    localTransformation = glm::scale(glm::mat4(1.0), glm::vec3(3.5,3.5,3.5));
    spotLightRenderable->setLocalTransform(localTransformation);

    HierarchicalRenderable :: addChild(visor, spotLightRenderable);               
    viewer.addSpotLight(spotLight);
    viewer.addRenderable(spotLightRenderable);

    HierarchicalRenderable :: addChild(visor, spotLightRenderable);               
    viewer.addSpotLight(spotLight);
    viewer.addRenderable(spotLightRenderable);
        
}

void initialize_scene( Viewer& viewer )
{
      

    ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(  "../../sfmlGraphicsPipeline/shaders/flatVertex.glsl",
                                                                    "../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");
    viewer.addShaderProgram( flatShader );
    ShaderProgramPtr phongShader = std::make_shared<ShaderProgram>( "../../sfmlGraphicsPipeline/shaders/phongVertex.glsl", 
                                                                    "../../sfmlGraphicsPipeline/shaders/phongFragment.glsl");
    viewer.addShaderProgram( phongShader );



    // ---------------- Lights ---------------

    glm::mat4 localTransformation;


    //Define a directional light for the whole scene
    glm::vec3 d_direction = glm::normalize(glm::vec3(0.0,-1.0,-1.0));
    glm::vec3 d_ambient(0.0,0.0,0.0), d_diffuse(0.3,0.3,0.1), d_specular(0.3,0.3,0.1);

    DirectionalLightPtr directionalLight = std::make_shared<DirectionalLight>(d_direction, d_ambient, d_diffuse, d_specular);
    //Add a renderable to display the light and control it via mouse/key event
    glm::vec3 lightPosition(0.0,0.0,20.0);
    DirectionalLightRenderablePtr directionalLightRenderable = std::make_shared<DirectionalLightRenderable>(flatShader, directionalLight, lightPosition);
    localTransformation = glm::scale(glm::mat4(1.0), glm::vec3(0.5,0.5,0.5));
    directionalLightRenderable->setLocalTransform(localTransformation);

    viewer.setDirectionalLight(directionalLight);
    viewer.addRenderable(directionalLightRenderable);

    // Adding submarine

    LightedMeshRenderablePtr* submarineGroup = new LightedMeshRenderablePtr[10];
    submarineGroup = createSubmarine(viewer,  phongShader);
    for (int i = 0; i < 10; i++)
    {
        viewer.addRenderable( submarineGroup[i] );
    }

    // ------------- Scenes -----------
    Scene1( viewer, submarineGroup[0], submarineGroup[1], flatShader);
    Scene2 ( viewer, phongShader, 19.0, 26.0, flatShader);
    Scene3 ( viewer,  phongShader, submarineGroup[0],  submarineGroup[1], submarineGroup[2] , 43, 40, flatShader);
    Scene4 ( viewer,  phongShader, submarineGroup[0],  submarineGroup[1], submarineGroup[2] , 83, 26, flatShader);
    
}

int main() 
{
	Viewer viewer(1280,720);
	initialize_scene(viewer);
    viewer.startAnimation();

	while( viewer.isRunning() )
	{
		viewer.handleEvent();
		viewer.animate();
		viewer.draw();
		viewer.display();    
        
        
	}	

	return EXIT_SUCCESS;
}