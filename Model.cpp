#define TINYOBJECTLOADER_IMPLEMENTATION

#include "Model.hpp"
#include "Vertex.hpp"
#include <TINY\tiny_obj_loader.h>

Model::Model(std::string path)
{
	std::vector<Vertex> Vertices;
	tinyobj::ObjReaderConfig config;
	tinyobj::ObjReader reader;

	// Try to parse the file
	bool loaded = reader.ParseFromFile(path, config);
	if (loaded == false)
	{
		// If an error was given then print it
		if (reader.Error().empty() == false)
		{
			std::cerr << "Issue whilst loading model: " << reader.Error() << "\n";
		}
		
		//? return
		exit(1);
	}

	// Print any warnings
	if (reader.Warning().empty() == false)
	{
		std::cerr << "Warning whilst loading model: " << reader.Warning() << "\n";
	}

	// Get the info from the loaded model
	// TODO: Don't use auto
	auto& attributes = reader.GetAttrib();
	auto& shapes = reader.GetShapes();

	// Loop through every shape of the object
	for (size_t shapeIndex = 0; shapeIndex < shapes.size(); shapeIndex++)
	{
		size_t index = 0;

		// Go over every face
		for (size_t faceIndex = 0; faceIndex < shapes[shapeIndex].mesh.num_face_vertices.size(); faceIndex++)
		{
			// Go over every vertex in every face		
			size_t verticesInFace = (size_t)(shapes[shapeIndex].mesh.num_face_vertices[faceIndex]);
			for (size_t vertexIndex = 0; vertexIndex < verticesInFace; vertexIndex++)
			{
				Vertex currentVertex;

				tinyobj::index_t tinyObjVertex = shapes[shapeIndex].mesh.indices[index + vertexIndex];
			}
			
		}
	}	
}