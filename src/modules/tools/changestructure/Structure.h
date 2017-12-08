#include "libs/Module.h"

using namespace std;
#include <math.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <algorithm>
#include "Panel.h"
#include <vector>
class ConfigValue;
class ConfigSource;
class ConfigCache;

class Structure : public Module{
	public:
		Structure();
      	void on_module_loaded();
      	void on_gcode_received(void* argument);

	private:
        ConfigCache* config_cache;            // A cache in which ConfigValues are kept
        vector<ConfigSource*> config_sources; // A list of all possible coniguration sources
};
