#include "Server.h"
#include <typeinfo.h>

int main1(int argc, char * argv []) {
	test();
	Player player;
	player.hp = 1;

	const type_info & info = typeid(Player);
	size_t code = info.hash_code();
	const char * pName = info.name();
	info.before(info);
	return 0;
}