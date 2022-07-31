STB_INCLUDE_PATH = /usr/include/stb/


CFLAGS	= -std=c++17 -O2
LDFLAGS	= -lglfw -lvulkan -ldl -lX11 -lXxf86vm -lXrandr -lXi -I$(STB_INCLUDE_PATH)

VulkanTest: compileShader
	g++ $(CFLAGS) -o HelloTriangle HelloTriangle.cpp $(LDFLAGS)

.PHONY: test clean loop

test: clean VulkanTest
	./HelloTriangle

compileShader:
	glslc shaders/shader.vert -o shaders/vert.spv
	glslc shaders/shader.frag -o shaders/frag.spv
deadloop:
	./HelloTriangle &
	make deadloop
clean:
	rm -f HelloTriangle
	rm -f ./shaders/*.spv


