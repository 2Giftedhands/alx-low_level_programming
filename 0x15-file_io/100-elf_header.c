#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - checks if a file is an ELF file.
 * @e_ident: pointer to an array containing the ELF magic numbers.
 *
 * Description: if the file is not an ELF file - exit code 98.
 */

/* Function to check if a file is an ELF file */
void check_elf(unsigned char *e_ident)
{
	/* Check if the first four bytes of the ELF header match the magic numbers */
	int index;

	for (index = 0; index < 4; index++)
{
		if (e_ident[index] != 127 &&
		    e_ident[index] != 'E' &&
		    e_ident[index] != 'L' &&
		    e_ident[index] != 'F')
		{
			/* Print an error message and exit with code 98 if not an ELF file */
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - rints the magic numbers of an ELF header.
 * @e_ident: pointer to an array containing the ELF magic numbers.
 *
 * Description: magic numbers are separated by spaces.
 */


/* Function to print magic numbers of an ELF header */
void print_magic(unsigned char *e_ident)
{
	int index;

	/* Print the magic numbers separated by spaces */
	printf("  Magic:   ");
	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);
		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * main - displays the information within the
 *        ELF header at the start of an ELF file.
 * @argc: number of arguments count in the program.
 * @argv: array of pointers to the arguments.
 *
 * Return: 0 if successful.
 *
 * Description: If the file is not an ELF File or
 *		function fails - exit code 98.
 */

/* Main function */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fd, bytes_read;

	/* Check if the correct number of arguments is provided */
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s <ELF file>\n", argv[0]);
		exit(98);
	}

	/* Open the ELF file */
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	/* Allocate memory for the ELF header */
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(fd);
		dprintf(STDERR_FILENO, "Error: Memory allocation failed\n");
		exit(98);
	}

	/* Read the ELF header */
	bytes_read = read(fd, header, sizeof(Elf64_Ehdr));
	if (bytes_read == -1)
	{
		free(header);
		close_elf(fd);
		dprintf(STDERR_FILENO, "Error: Failed to read file %s\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);

	printf("ELF Header:\n");

	print_magic(header->e_ident);

	free(header);
	close_elf(fd);

	return (0);
}
