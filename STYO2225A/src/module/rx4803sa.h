
int RTC_init(void);
void RTC_set_date_long(int year,int month,int day,int week,int hour,int minute,int second);
void RTC_get_date_long(int *year,int *month,int *day,int *week,int *hour,int *minute,int *second);
uint32_t DateToTimer(int year,int month,int day,int hour,int minute,int second);
uint32_t GetTime(void);






















