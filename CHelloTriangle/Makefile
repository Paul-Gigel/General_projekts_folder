CFLAGS	= -std=c++17 -O2
LDFLAGS	= -lglfw -lvulkan -ldl -lX11 -lXxf86vm -lXrandr -lXi

VulkanTest:
	g++ $(CFLAGS) -o HelloTriangle HelloTriangle.cpp $(LDFLAGS)

.PHONY: test clean loop

test: clean VulkanTest
	./HelloTriangle

deadloop:
	./HelloTriangle &
	make deadloop
clean:
	rm -f HelloTriangle


