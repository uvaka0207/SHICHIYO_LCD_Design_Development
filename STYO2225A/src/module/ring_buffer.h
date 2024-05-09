#ifndef RING_BUFFER_DEF
#define RING_BUFFER_DEF



/*
 *		リングバッファモジュール
 */
typedef struct{
	uint8_t *buffer;
	int buffer_size;
	int read_ptr;
	int write_ptr;
}RING_BUFFER;

extern void ring_buffer_init(RING_BUFFER *ring , int size);
extern void ring_buffer_delete(RING_BUFFER *ring);
extern int ring_buffer_write(uint8_t data , RING_BUFFER *ring);
extern int ring_buffer_write_block(uint8_t data[] , int size , RING_BUFFER *ring);

extern int ring_buffer_read(uint8_t *data , RING_BUFFER *ring);
extern int ring_buffer_read_block(uint8_t data[] , int size , RING_BUFFER *ring);
extern int ring_buffer_get_size(RING_BUFFER *ring);
extern int ring_buffer_get_free_size(RING_BUFFER *ring);
extern void ring_buffer_clr(RING_BUFFER *ring);


#endif
