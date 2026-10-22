#include "Model.hpp"

Model::Model(std::string path)
{
	std::vector<Vertex> vertices;
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
				// Convert the tiny obj vertex to our own one
				tinyobj::index_t tinyObjVertex = shapes[shapeIndex].mesh.indices[index + vertexIndex];
				Vertex currentVertex(attributes, tinyObjVertex);

				// Add it to the model
				vertices.push_back(currentVertex);
			}
			
			// Move over to the next one
			index += verticesInFace;
		}
	}

	// Drawing settings
	drawCount = (GLuint)vertices.size();

	// Make the vertex array
	GLuint vbo;
	{
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
	}

	// Make the vertex attribute things
	{
		//? idk how good this whole dynamic thing is but it does make it kinda easier maybe
		// TODO: Do a thing where you just write in like GenerateAttributes(3, 2, 3);
		int attributeIndex = 0;
		int dataIndex = 0;
		int currentSize = 0;

		// Vertices
		currentSize = 3;
		glVertexAttribPointer(attributeIndex, currentSize, GL_FLOAT, GL_FALSE, Vertex::SizeOfNumberOfNumbers(), (GLvoid*)(dataIndex * sizeof(GLfloat)));
		glEnableVertexAttribArray(attributeIndex++);
		dataIndex += currentSize;

		// Texture coordinates
		currentSize = 2;
		glVertexAttribPointer(attributeIndex, currentSize, GL_FLOAT, GL_FALSE, Vertex::SizeOfNumberOfNumbers(), (GLvoid*)(dataIndex * sizeof(GLfloat)));
		glEnableVertexAttribArray(attributeIndex++);
		dataIndex += currentSize;

		// Normals
		currentSize = 3;
		glVertexAttribPointer(attributeIndex, currentSize, GL_FLOAT, GL_FALSE, Vertex::SizeOfNumberOfNumbers(), (GLvoid*)(dataIndex * sizeof(GLfloat)));
		glEnableVertexAttribArray(attributeIndex++);
		dataIndex += currentSize;
	}
}

void Model::Draw()
{
	// Turn on the shader
	GLuint shader = Graphics::Shaders::GetBasicShader();
	glUseProgram(shader);
	SendMatricesToShader(shader);

	// Activate and add the texture
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture->GetTexture());
	Graphics::SetShaderVariable(shader, "Texture0", 0);

	// Draw it
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, drawCount);
	glBindVertexArray(0);

	// Disable the shader just to be safe
	glUseProgram(0);
}