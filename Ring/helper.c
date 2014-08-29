#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool isNumber(const char *str){
  bool result = true;
  if (str == NULL){
    return false;	
  }	
  else{
    for (int i = 0; i < strlen(str);i++){
      if (isdigit(str[i]) == 0){
	result = false;
	break;
      }
    }
  }
  return result;
}

bool isPort(const char *str){
	bool result = false;
	if (isNumber(str) == true){
		int port=atoi(str);
		if (port>0 && port<65535){
			result = true;
		}	
	}
	return result;	
}


bool isIP(const char *str){

	bool result = false;

	if (str == NULL){

		return false;

	}

	const char *dot1, *dot2, *dot3, *dot4;

	dot1 = strstr(str, ".");

	dot2 = strstr(dot1+1, ".");

	dot3 = strstr(dot2+1 ,".");

	dot4 = strstr(dot3+1, ".");

	if (dot1 != NULL && dot2 != NULL &&dot3 != NULL &&dot4 == NULL){

		char ip1[10];

		char ip2[10];

		char ip3[10];

		char ip4[10];

		int i = 0;

		int count = 0;

		for (; str + i < dot1; i++){

			ip1[i] = str[i];

		}

		ip1[i] = '\0';

		i ++;

		for (; str+i < dot2; i++,count++){

			ip2[count] = str[i];

		}

		ip2[count] = '\0';

		i ++;

		count = 0;

		for (; str+ i < dot3;i++, count++){

			ip3[count] = str[i];

		}

		ip3[count] = '\0';

		i ++;

		count = 0;

		for (int j = 0; str + i <str+ strlen(str); i++,count++){

			ip4[j] = str[i];

		}

		ip4[count] = '\0';



		if (isNumber(ip1) == true && isNumber(ip2) == true && isNumber(ip3) == true && isNumber(ip4) == true){

			int ip1_n = atoi(ip1);

			int ip2_n = atoi(ip2);

			int ip3_n = atoi(ip3);

			int ip4_n = atoi(ip4);

			if (ip1_n >= 0 && ip1_n < 256 && ip2_n >= 0 && ip2_n < 256 && ip3_n >= 0 && ip3_n < 256 && ip4_n >= 0 && ip4_n < 256){

				result = true;

			}

		}

	}

	return result;

}


