#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * check_if_elf_file - checks if the file is a valid ELF file.
 * @e_ident: Pointer to array of the ELF magic numbers.
 *
 * Description: If the file is not a valid ELF file, exit with status code 98
 */
void check_if_elf_file(unsigned char *e_ident)
{
	int index;

	index = 0;
	while (index < 4)
	{
		if (e_ident[index] != 127 &&
			e_ident[index] != 'E' &&
			e_ident[index] != 'L' &&
			e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
		index++;
	}
}

/**
 * write_magic - prints the magic numbers of an ELF header.
 * @e_ident: Pointer to array of the ELF magic numbers.
 *
 * Description: The magic numbers are the first 4 bytes of the ELF header.
 */
void write_magic(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");
	index = 0;
	while (index < EI_NIDENT)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}

		index++;
	}
}

/**
 * write_class - prints the class of an ELF header.
 * @e_ident: pointer to array of the ELF magic numbers.
 */
void write_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	if (e_ident[EI_CLASS] == ELFCLASSNONE)
	{
		printf("none\n");
	}
	else if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		printf("ELF32\n");
	}
	else if (e_ident[EI_CLASS] == ELFCLASS64)
	{
		printf("ELF64\n");
	}
	else
	{
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - prints the data of an ELF header.
 * @e_ident: pointer to array of the ELF magic numbers.
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	if (e_ident[EI_DATA] == ELFDATANONE)
	{
		printf("none\n");
	}
	else if (e_ident[EI_DATA] == ELFDATA2LSB)
	{
		printf("2's complement, little endian\n");
	}
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		printf("2's complement, big endian\n");
	}
	else
	{
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * write_version - prints the version of an ELF header.
 * @e_ident: pointer to array of the ELF magic numbers.
 */
void write_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
		   e_ident[EI_VERSION]);

	if (e_ident[EI_VERSION] == EV_CURRENT)
	{
		printf(" (current)\n");
	}
	else
	{
		printf("\n");
	}
}

/**
 * write_osabi - prints the OS/ABI of an ELF header.
 * @e_ident: pointer to array of the ELF magic numbers.
 */
void write_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	if (e_ident[EI_OSABI] == ELFOSABI_NONE)
	{
		printf("UNIX - System V\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_HPUX)
	{
		printf("UNIX - HP-UX\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_NETBSD)
	{
		printf("UNIX - NetBSD\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_LINUX)
	{
		printf("UNIX - Linux\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
	{
		printf("UNIX - Solaris\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_IRIX)
	{
		printf("UNIX - IRIX\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_FREEBSD)
	{
		printf("UNIX - FreeBSD\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_TRU64)
	{
		printf("UNIX - TRU64\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_ARM)
	{
		printf("ARM\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_STANDALONE)
	{
		printf("Standalone App\n");
	}
	else
	{
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * write_abi - prints the ABI version of an ELF header.
 * @e_ident: pointer to array of the ELF magic numbers.
 */
void write_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
		   e_ident[EI_ABIVERSION]);
}

/**
 * write_type - prints the type of an ELF header.
 * @e_type: ELF type.
 * @e_ident: pointer to array of the ELF magic numbers.
 */
void write_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * write_entry - prints the entry point of an ELF header.
 * @e_entry: address of the entry point.
 * @e_ident: pointer to array of the ELF magic numbers.
 */
void write_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
				  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf_file - closes an ELF file.
 * @elf: file descriptor of an ELF file.
 *
 * Description: exits with code 98 on failure.
 */
void close_elf_file(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - displays the information contained in the
 * 	  ELF header at the start of an ELF file.
 * @ac: number of arguments passed to the program.
 * @av: array of pointers to the arguments.
 *
 * Return: on success - EXIT_SUCCESS.
 *
 * Description: if the file is not an ELF file, or on failure,
 * 		exit with code 98.
 */
int main(int ac, char *av[])
{
	Elf64_Ehdr *header;
	int o, r;

	(void)ac;

	o = open(av[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", av[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (!header)
	{
		close_elf_file(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", av[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header), close_elf_file(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", av[1]);
		exit(98);
	}

	check_if_elf_file(header->e_ident);
	printf("ELF Header:\n");
	write_magic(header->e_ident);
	write_class(header->e_ident);
	print_data(header->e_ident);
	write_version(header->e_ident);
	write_osabi(header->e_ident);
	write_abi(header->e_ident);
	write_type(header->e_type, header->e_ident);
	write_entry(header->e_entry, header->e_ident);

	free(header), close_elf_file(o);
	return (0);
}
