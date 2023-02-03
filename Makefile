all: compile run

# change for the workspace folder
folder=assignment-2

# Compiling the program
compile:
	@echo "Compiling..."
	@g++ -g -o ./bin/$(folder)-$(q) ./$(folder)/$(q).cpp

# Running the program
run:
	@echo "Running..."
	@./bin/$(folder)-$(q).exe