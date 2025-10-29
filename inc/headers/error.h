
#ifndef ERROR_H
# define ERROR_H

# define PLAYER_NUMBER_ERROR -1
# define EXIT_NUMBER_ERROR -2
# define COLLECTABLE_NUMBER_ERROR -3
# define BORDER_ERROR -4
# define INVALID_CHAR_ERROR -5
# define FILE_EXTENSION_ERROR -6
# define INVALID_PATH_ERROR -7
# define PLAYER_NUMBER_MSG "Error: There must be exactly one player ('E') on the map.\n"
# define EXIT_NUMBER_MSG "Error: There must be exactly one exit ('E') on the map.\n"
# define COLLECTABLE_NUMBER_MSG "Error: There must be at least one collectable ('C') on the map.\n"
# define BORDER_MSG "Error: The map must be surrounded by walls ('1').\n"
# define INVALID_CHAR_MSG "Error: The map contains invalid characters.\n"
# define FILE_EXTENSION_MSG "Error: The map file must have a .ber extension.\n"
# define MISSING_FILE_MSG "Error: No map file provided.\n"
# define INVALID_PATH_MSG "Error: The player ('P') should be able to reach every collectable ('C') and the exit ('E').\n"

#endif