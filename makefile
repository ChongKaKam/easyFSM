all: easyFSM
easyFSM: test.cpp
	@g++-11 -o easyFSM test.cpp
test: easyFSM
	@./easyFSM
.PHONY: clean
clean:
	@rm easyFSM