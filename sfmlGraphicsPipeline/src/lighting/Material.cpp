#include "./../../include/lighting/Material.hpp"
#include <glm/gtc/type_ptr.hpp>

Material::~Material()
{}

Material::Material()
{
    m_ambient = glm::vec3(0.0,0.0,0.0);
    m_diffuse = glm::vec3(0.0,0.0,0.0);
    m_specular = glm::vec3(0.0,0.0,0.0);
    m_shininess = 0.0;
}

Material::Material(const glm::vec3& ambient, const glm::vec3& diffuse, const glm::vec3& specular, const float &shininess)
{
    m_ambient = ambient;
    m_diffuse = diffuse;
    m_specular = specular;
    m_shininess = shininess;
}

Material::Material(const Material& material)
{
    m_ambient = material.m_ambient;
    m_diffuse = material.m_diffuse;
    m_specular = material.m_specular;
    m_shininess = material.m_shininess;
}

const glm::vec3& Material::ambient() const
{
    return m_ambient;
}

void Material::setAmbient(const glm::vec3 &ambient)
{
    m_ambient = ambient;
}

const glm::vec3& Material::diffuse() const
{
    return m_diffuse;
}

void Material::setDiffuse(const glm::vec3 &diffuse)
{
    m_diffuse = diffuse;
}

const glm::vec3& Material::specular() const
{
    return m_specular;
}

void Material::setSpecular(const glm::vec3 &specular)
{
    m_specular = specular;
}

void Material::setShininess(float shininess)
{
    m_shininess = shininess;
}

const float &Material::shininess() const
{
    return m_shininess;
}

bool Material::sendToGPU(const ShaderProgramPtr& program, const MaterialPtr &material)
{
    bool success = true;
    int location = -1;

    if(program==nullptr || material==nullptr)
    {
        return false;
    }

    location = program->getUniformLocation("material.ambient");
    if(location!=ShaderProgram::null_location)
    {
        glcheck(glUniform3fv(location, 1, glm::value_ptr(material->ambient())));
    }
    else
    {
        success = false;
    }

    location = program->getUniformLocation("material.diffuse");
    if(location!=ShaderProgram::null_location)
    {
        glcheck(glUniform3fv(location, 1, glm::value_ptr(material->diffuse())));
    }
    else
    {
        success = false;
    }

    location = program->getUniformLocation("material.specular");
    if(location!=ShaderProgram::null_location)
    {
        glcheck(glUniform3fv(location, 1, glm::value_ptr(material->specular())));
    }
    else
    {
        success = false;
    }

    location = program->getUniformLocation("material.shininess");
    if(location!=ShaderProgram::null_location)
    {
        glcheck(glUniform1f(location, material->shininess()));
    }
    else
    {
        success = false;
    }

    return success;
}

MaterialPtr Material::Pearl()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.25, 0.20725, 0.20725);
    glm::vec3 diffuse(1.0, 0.829, 0.829);
    glm::vec3 specular(0.296648, 0.296648, 0.296648);
    float shininess = openGLFactor*0.088;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}

MaterialPtr Material::Emerald()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.0215, 0.1745, 0.0215);
    glm::vec3 diffuse(0.07568, 0.61424, 0.07568);
    glm::vec3 specular(0.633, 0.727811, 0.633);
    float shininess = openGLFactor*0.6;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}

MaterialPtr Material::Bronze()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.2125, 0.1275, 0.054);
    glm::vec3 diffuse(0.714, 0.4284, 0.18144);
    glm::vec3 specular(0.393548, 0.271906, 0.166721);
    float shininess = openGLFactor*0.2;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}


MaterialPtr Material::Turquoise()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.1, 0.18725, 0.1745);
    glm::vec3 diffuse(0.396, 0.74151, 0.69102);
    glm::vec3 specular(0.297254, 0.30829, 0.306678);
    float shininess = openGLFactor*0.1;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}

MaterialPtr Material::WhiteRubber()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.05, 0.05, 0.05);
    glm::vec3 diffuse(0.5, 0.5, 0.5);
    glm::vec3 specular(0.7, 0.7, 0.7);
    float shininess = openGLFactor*0.078125;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}

MaterialPtr Material::YellowRubber()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.05, 0.05, 0.0);
    glm::vec3 diffuse(0.5, 0.5, 0.4);
    glm::vec3 specular(0.7, 0.7, 0.04);
    float shininess = openGLFactor*0.078125;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}

MaterialPtr Material::BlackRubber()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.02, 0.02, 0.02);
    glm::vec3 diffuse(0.01, 0.01, 0.01);
    glm::vec3 specular(0.4, 0.4, 0.4);
    float shininess = openGLFactor*0.078125;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}

MaterialPtr Material::CyanRubber()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.0, 0.05, 0.05);
    glm::vec3 diffuse(0.4, 0.5, 0.5);
    glm::vec3 specular(0.04, 0.7, 0.7);
    float shininess = openGLFactor*0.078125;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}

MaterialPtr Material::GreenRubber()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.0, 0.05, 0.0);
    glm::vec3 diffuse(0.4, 0.5, 0.4);
    glm::vec3 specular(0.04, 0.7, 0.04);
    float shininess = openGLFactor*0.078125;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}

MaterialPtr Material::RedRubber()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.05, 0.0, 0.0);
    glm::vec3 diffuse(0.5, 0.4, 0.4);
    glm::vec3 specular(0.7, 0.04, 0.04);
    float shininess = openGLFactor*0.078125;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}

MaterialPtr Material::Silver()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.19225, 0.19225, 0.19225);
    glm::vec3 diffuse(0.50754, 0.50754, 0.50754);
    glm::vec3 specular(0.508273, 0.508273, 0.508273);
    float shininess = openGLFactor*0.4;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}

MaterialPtr Material::Gold()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.24725, 0.1995, 0.0745);
    glm::vec3 diffuse(0.75164, 0.60648, 0.22648);
    glm::vec3 specular(0.628281, 0.555802, 0.366065);
    float shininess = openGLFactor*0.4;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}

MaterialPtr Material::Ruby()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.1745, 0.01175, 0.01175);
    glm::vec3 diffuse(0.61424, 0.04136, 0.04136);
    glm::vec3 specular(0.727811, 0.626959, 0.626959);
    float shininess = openGLFactor*0.6;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}

MaterialPtr Material::Chrome()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.25, 0.25, 0.25);
    glm::vec3 diffuse(0.4, 0.4, 0.4);
    glm::vec3 specular(0.774597, 0.774597, 0.774597);
    float shininess = openGLFactor*0.6;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}

MaterialPtr Material::Jade()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.135, 0.2225, 0.1575);
    glm::vec3 diffuse(0.54, 0.89, 0.63);
    glm::vec3 specular(0.316228, 0.316228, 0.316228);
    float shininess = openGLFactor*0.1;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}

MaterialPtr Material::Brass()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.329412, 0.223529, 0.027451);
    glm::vec3 diffuse(0.780392, 0.568627, 0.113725);
    glm::vec3 specular(0.992157, 0.941176, 0.807843);
    float shininess = openGLFactor*0.21794872;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}

MaterialPtr Material::Copper()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.19125, 0.0735, 0.0225);
    glm::vec3 diffuse(0.7038, 0.27048, 0.0828);
    glm::vec3 specular(0.256777, 0.137622, 0.086014);
    float shininess = openGLFactor*0.1;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}

MaterialPtr Material::Obsidian()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.05375, 0.05, 0.06625);
    glm::vec3 diffuse(0.18275, 0.17, 0.22525);
    glm::vec3 specular(0.332741, 0.328634, 0.346435);
    float shininess = openGLFactor*0.3;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}

MaterialPtr Material::Green()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.0, 0.0, 0.0);
    glm::vec3 diffuse(0.1, 0.35, 0.1);
    glm::vec3 specular(0.45, 0.55, 0.45);
    float shininess = openGLFactor*0.25;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}

MaterialPtr Material::Red()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.0, 0.0, 0.0);
    glm::vec3 diffuse(0.5, 0.0, 0.0);
    glm::vec3 specular(0.7, 0.6, 0.6);
    float shininess = openGLFactor*0.25;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}

MaterialPtr Material::Cyan()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.0, 0.1, 0.06);
    glm::vec3 diffuse(0.0, 0.50980392, 0.50980392);
    glm::vec3 specular(0.50196078, 0.50196078, 0.50196078);
    float shininess = openGLFactor*0.25;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}

MaterialPtr Material::Yellow()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.0, 0.0, 0.0);
    glm::vec3 diffuse(0.5, 0.5, 0.0);
    glm::vec3 specular(0.60, 0.60, 0.50);
    float shininess = openGLFactor*0.25;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}

MaterialPtr Material::Black()
{
    float openGLFactor=128.0;
    glm::vec3 ambient(0.0, 0.0, 0.0);
    glm::vec3 diffuse(0.01, 0.01, 0.01);
    glm::vec3 specular(0.50, 0.50, 0.50);
    float shininess = openGLFactor*0.25;
    return std::make_shared<Material>(ambient, diffuse, specular, shininess);
}