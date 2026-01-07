# Build directories
ROOT := ./
MODULES := $(ROOT)/src/sdlmenu/ $(ROOT)/src/testclient/ 
					#	$(ROOT) \
					#	$(ROOT) 
						
BIN_DIR := build/bin/src
ARTIFACTS_DIR := build/src/artifacts

GO_PROXY := direct
TAG ?= latest

.PHONY: build clean test run
	
build: build-sdlmenu build-client

build-sdlmenu:
	@echo "building sdlmenu"
	(cd src/sdlmenu && go build -tags static -v -o ../../$(BIN_DIR)/sdlmenu/sdlmenu)

build-client:
	@echo "building client"
	(cd src/testclient && go build -v -o ../../$(BIN_DIR)/testclient/testclient)

run-sdlmenu:
	@echo "running sdlmenu"
	(./$(BIN_DIR)/sdlmenu/sdlmenu)

run-client:
	@echo "running client"
	(./$(BIN_DIR)/testclient/testclient)

clean:
	@echo "Cleaning build artifacts..."
	@rm -rf $(BIN_DIR) $(ARTIFACT_DIR)

test:
	@for module in $(MODULE_DIRS); do \
		echo "Testing $$module..."; \
		(cd $$module && GO111MODULE=on go test -v ./...); \
	done


vendor:
	@for module in $(MODULE_DIRS); do \
		echo "Vendoring dependencies for $$module..."; \
		(cd $$module && GO111MODULE=on go mod vendor); \
	done


# Dependency resolution between modules
$(BIN_DIR)/router: $(BIN_DIR)/sdlmenu $(BIN_DIR)/cli

# Module installation (if needed as dependencies)
install-modules:
	@echo "Installing modules to GOPATH..."
	@for module in $(MODULE_DIRS); do \
		echo "Installing $$module..."; \
		(cd $$module && GO111MODULE=on go install); \
	done

