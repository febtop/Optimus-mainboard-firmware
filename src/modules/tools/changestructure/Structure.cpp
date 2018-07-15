#include "modules/communication/utils/Gcode.h"
#include "Structure.h"
#include "libs/StreamOutput.h"
#include "libs/StreamOutputPool.h"
#include "libs/ConfigSources/FileConfigSource.h"
#include "libs/ConfigSources/FirmConfigSource.h"
#include "libs/Config.h"
#include "libs/Kernel.h"
#include "libs/Module.h"
#include "libs/utils.h"
Structure::Structure(){
}

void Structure::on_module_loaded()
{
    this->register_for_event(ON_GCODE_RECEIVED);
}

void Structure::on_gcode_received(void *argument){
    Gcode *gcode = static_cast<Gcode*>(argument);
    if(gcode->has_m){
    	if(gcode->m == 1){

    		if(!(gcode->has_letter('D'))&&!(gcode->has_letter('C'))&&!(gcode->has_letter('P')))
    		{

        		if(!(file_exists("/sd/config.delta"))){
        			//gcode->stream->printf("?Delta\r\n");
        			gcode->stream->printf("!Delta\r\n");
        		}
        		else if(!(file_exists("/sd/config.cartisian"))){
        			//gcode->stream->printf("?Cartisian\r\n");
        			gcode->stream->printf("!Cartisian\r\n");
        		}
        		else if(!(file_exists("/sd/config.prusa"))){
        			//gcode->stream->printf("?Prusa\r\n");
        			gcode->stream->printf("!Prusa\r\n");
        		}
        		else if(!(file_exists("/sd/config.lasercartisian"))){
        			//gcode->stream->printf("?Laser_C\r\n");
        			gcode->stream->printf("!Laser_C\r\n");
        		}
    					}
    		else
    		{

        		if(!(file_exists("/sd/config.delta"))){
        			//gcode->stream->printf("?Delta\r\n");
        			rename("/sd/config.txt","/sd/config.delta");
        		}
        		else if(!(file_exists("/sd/config.cartisian"))){
        			//gcode->stream->printf("?Cartisian\r\n");
        			rename("/sd/config.txt","/sd/config.cartisian");
        		}
        		else if(!(file_exists("/sd/config.prusa"))){
        			//gcode->stream->printf("?Prusa\r\n");
        			rename("/sd/config.txt","/sd/config.prusa");
        		}
        		else if(!(file_exists("/sd/config.lasercartisian"))){
        		    //gcode->stream->printf("?Laser_C\r\n");
        		    rename("/sd/config.txt","/sd/config.lasercartisian");
        		}


    			if(gcode->has_letter('D')){
            		rename("/sd/config.delta","/sd/config.txt");
            		gcode->stream->printf("!Delta\r\n");
    			}
    			else if(gcode->has_letter('C')){
    				if(!(gcode->has_letter('L'))){
        				rename("/sd/config.cartisian","/sd/config.txt");
        				gcode->stream->printf("!Cartisian\r\n");
    				}
    				else{
        				rename("/sd/config.lasercartisian","/sd/config.txt");
        				gcode->stream->printf("!Laser_C\r\n");
    				}
    			}
    			else if(gcode->has_letter('P'))
    			{
    				rename("/sd/config.prusa","/sd/config.txt");
    				gcode->stream->printf("!Prusa\r\n");
    			}
    		}
    		}

    	    }
    	}

