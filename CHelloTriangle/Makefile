STB_INCLUDE_PATH = /usr/include/stb/
TINYOBJ_INCLUDE_PATH = /usr/include/tiny_obj_loader

CFLAGS	= -std=c++17 -O3
LDFLAGS	= -lglfw -lvulkan -ldl -lX11 -lXxf86vm -lXrandr -lXi -I$(STB_INCLUDE_PATH) -I$(TINYOBJ_INCLUDE_PATH)

VulkanTest: compileShader
	g++ $(CFLAGS) -o HelloTriangle HelloTriangle.cpp $(LDFLAGS)

.PHONY: test clean loop

test: clean VulkanTest exe
	rm -f HelloTriangle ./shaders/*.spv

exe :
	./HelloTriangle

compileShader:
	glslc shaders/shader.vert -o shaders/vert.spv
	glslc shaders/shader.frag -o shaders/frag.spv
deadloop:
	./HelloTriangle &
	make deadloop
clean:
	rm -f HelloTriangle ./shaders/*.spv


