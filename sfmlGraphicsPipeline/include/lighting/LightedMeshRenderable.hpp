#ifndef LIGHTED_MESH_RENDERABLE_HPP
#define LIGHTED_MESH_RENDERABLE_HPP

#include "./../HierarchicalRenderable.hpp"
#include "./../lighting/Material.hpp"
#include "./../lighting/Light.hpp"
#include "./../KeyframeCollection.hpp" 

#include <string>
#include <vector>
#include <glm/glm.hpp>

class LightedMeshRenderable : public HierarchicalRenderable
{
    public:
        ~LightedMeshRenderable();
        LightedMeshRenderable(ShaderProgramPtr program, const std::string& filename);
        LightedMeshRenderable(ShaderProgramPtr shaderProgram, const std::vector< glm::vec3 >& positions, const std::vector<unsigned int>& indices,
                              const std::vector<glm::vec3>& normals, const std::vector<glm::vec2>& texCoords);
        void setMaterial(const MaterialPtr& material);
        std::vector< glm::vec3 > & positions();
        const std::vector< glm::vec3 > & positions() const;
        std::vector< unsigned int >& indices();
        const std::vector< unsigned int >& indices() const;


        void addLocalTransformKeyframe( const GeometricTransformation& transformation, float time );
        void addParentTransformKeyframe( const GeometricTransformation& transformation, float time );


    private:
        void do_draw();
        void do_animate( float time );

        std::vector< glm::vec3 > m_positions;
        std::vector< glm::vec3 > m_normals;
        std::vector< glm::vec4 > m_colors;
        std::vector< unsigned int > m_indices;

        KeyframeCollection m_localKeyframes; /*!< A collection of keyframes for the local transformation of renderable. */
        KeyframeCollection m_parentKeyframes; /*!< A collection of keyframes for the parent transformation of renderable. */


        unsigned int m_pBuffer;
        unsigned int m_cBuffer;
        unsigned int m_nBuffer;
        unsigned int m_iBuffer;

        MaterialPtr m_material;
};

typedef std::shared_ptr<LightedMeshRenderable> LightedMeshRenderablePtr;

#endif
