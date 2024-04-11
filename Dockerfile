# Use a base image with the necessary build tools and libraries for compiling C code
FROM gcc:latest

# Set the working directory inside the container
WORKDIR /usr/src/app

# Copy the current directory contents into the container at /usr/src/app
COPY . .

# Compile the C code
RUN make

# Command to run the compiled program
CMD ["./minishell"]
