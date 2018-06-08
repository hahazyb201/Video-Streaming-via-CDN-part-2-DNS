#include "DNSHeader.h"
#include "DNSQuestion.h"
#include "DNSRecord.h"
#include <string>


void parseQmsg(char * msg, DNSHeader * header, DNSQuestion * question);
void parseRmsg(char * msg, DNSHeader * header, DNSRecord * record);

int convertToQmsg(char * msg, DNSHeader * header, DNSQuestion * question);
int convertToRmsg(char * msg, DNSHeader * header, DNSRecord * record);

void header_to_msg(char * msg, DNSHeader * header, int &i);
void ip_to_data(char * rdata, std::string ip);
void parseIp(char * rdata, char * ip);

// helper function
ushort msg_to_ushort(char *msg, int &i);
void msg_to_header(char * msg, DNSHeader * header, int &i);
void msg_to_name(char * msg, char * name, int &i);

void ushort_to_msg(char * msg, ushort value, int &i);
void name_to_msg(char * msg, char * name, int &i);
void head_to_msg(char * msg, DNSHeader * header, int &i);

