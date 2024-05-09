
enum buzzer_id{
	BUZZER_NON,
	BUZZER_OK,
	BUZZER_NG,
	BUZZER_END,
	BUZZER_ERR
};



extern void buzzer(enum buzzer_id id);
extern void buzzer_stop(uint8_t depth);
extern void buzzer_ctrl(void);
extern int get_buzzer_stat(uint8_t depth);

extern void init_buzzer(void);
extern int Buzzer_Task(void);
