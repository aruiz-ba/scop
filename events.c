#include "scop.h"

void	key_to_transform(t_key *key, int keyStates[256])
{
	if (keyStates[119] == 1)
		key->rot_x += 0.1f;
	if (keyStates[115] == 1)
		key->rot_x -= 0.1f;
	if (keyStates[97] == 1)
		key->rot_y += 0.1f;
	if (keyStates[100] == 1)
		key->rot_y -= 0.1f;
	if (keyStates[106] == 1)
		key->zoom -= 0.01f;
	if (keyStates[107] == 1)
		key->zoom += 0.01f;
	printf("rot_x value %f\n", key->rot_x);
	printf("keystate: %i\n", keyStates[119]);
}
