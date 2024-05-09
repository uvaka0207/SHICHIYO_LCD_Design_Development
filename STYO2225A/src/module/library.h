int GetLineCount(wchar_t string[]);
void StringMidLine(wchar_t dest_string[] , wchar_t src_string[] , int start , int lines);


int GetFlag(uint8_t buf[] ,int id);
void SetFlag(uint8_t buf[] ,int id , int set);



int days_of_month(int year , int month);
int get_week(int year , int month , int date);

uint32_t time_to_sec(int year , int month ,int date ,int hour ,int minute ,int second);
void sec_to_time(uint32_t t , int *year , int *month ,int *date ,int *hour ,int *minute ,int *second);
uint32_t	get_now_clock_sec(void);




void SetClockObject(int obj);
void SetObjectTimeShort(int obj , uint32_t time);
void SetObjectTimeLong(int obj , uint32_t time);
wchar_t *GetStringTimeShort(wchar_t *buf, int buf_size , uint32_t time);


int  get_backlight(void);

