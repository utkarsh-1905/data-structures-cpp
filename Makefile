all: compile run

# change for the workspace folder
folder=practice/stack

# Compiling the program
compile:
	@echo "Compiling..."
	@g++ -g -o ./bin/$(q) ./$(folder)/$(q).cpp

# Running the program
run:
	@echo "Running..."
	@./bin/$(q).exe