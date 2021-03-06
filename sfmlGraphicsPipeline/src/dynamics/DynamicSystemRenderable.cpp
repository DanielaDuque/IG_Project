#include <cmath>
#include <iostream>
#include <map>
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/random.hpp>

#include "./../../include/gl_helper.hpp"
#include "./../../include/dynamics/DynamicSystemRenderable.hpp"
#include "./../../include/Viewer.hpp"

#include <iostream> 

DynamicSystemRenderable::~DynamicSystemRenderable()
{}

DynamicSystemRenderable::DynamicSystemRenderable(DynamicSystemPtr system) :
    HierarchicalRenderable(nullptr), m_lastUpdateTime( 0 )
{
    m_system = system;
}

void DynamicSystemRenderable::do_draw()
{}

void DynamicSystemRenderable::do_animate(float time )
{
    //std::cout << m_lastUpdateTime << " "<<time<<std::endl;
    if( time - m_lastUpdateTime >= m_system->getDt() )
    {
        //Dynamic system step
        m_system->computeSimulationStep();
        m_lastUpdateTime = time;
    }
    if(time > 0 && time <0.1 || m_lastUpdateTime > 113-m_system->getDt() ){
      
        for( const ParticlePtr& p : m_system->getParticles() )
        {
            p->restart();
            
        }
        m_lastUpdateTime = 0;
    }

}

void DynamicSystemRenderable::setDynamicSystem(const DynamicSystemPtr &system)
{
    m_system = system;
}

void DynamicSystemRenderable::do_keyPressedEvent(sf::Event &e)
{
    if(e.key.code == sf::Keyboard::A ) //Toggle collision detection
    {
        m_system->setCollisionsDetection( !m_system->getCollisionDetection() );
    }
    else if(e.key.code == sf::Keyboard::T ) //Tilt particles
    {
        srand(time(0));
        // "tilt" all particles randomly around their position
        for(const ParticlePtr& p : m_system->getParticles()) {
            glm::vec3 pos = p->getPosition();
            // tilt all positions
            pos += glm::ballRand(1.0f);
            p->setPosition(pos);
        }
    }
    else if( e.key.code == sf::Keyboard::F5 ) //Reset the simulation
    {
        for( const ParticlePtr& p : m_system->getParticles() )
        {
            p->restart();
        }
        m_lastUpdateTime = 0;
    }
     else if( e.key.code == sf::Keyboard::P){
        float Dt_last = m_system->getDt() ;
        m_system->setDt(2);
        m_system->computeSimulationStep();
        m_system->setDt(Dt_last);  
        m_lastUpdateTime +=2;    
    }
    else if( e.key.code == sf::Keyboard::O){
        m_lastUpdateTime -=2;
        float Dt_last = m_system->getDt() ;
        m_system->setDt(-2);
        m_system->computeSimulationStep();
        m_system->setDt(Dt_last);
    }
    else //Propagate events to the children
    {
        for(HierarchicalRenderablePtr c : getChildren())
        {
            c->keyPressedEvent(e);
        }
    }
}

void DynamicSystemRenderable::do_keyReleasedEvent(sf::Event& e)
{
    //Propagate events to the children
    for(HierarchicalRenderablePtr c : getChildren())
    {
        c->keyReleasedEvent(e);
    }
}
