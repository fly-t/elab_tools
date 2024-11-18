#include "elab_common.h"
int main(void)
{
    // 初始化调试串口，假设波特率为9600
    elab_debug_uart_init(9600);

    // 准备要发送的数据
    char message[] = "Hello, eLab Project!\n";

    // 调用发送函数，将消息发送到控制台
    elab_debug_uart_send(message, sizeof(message) - 1);

    // 创建一个缓冲区，用于接收输入
    char input_buffer[1];

    // 提示用户输入字符
    char prompt[] = "Please press a key: ";
    elab_debug_uart_send(prompt, sizeof(prompt) - 1);

    // 等待用户输入，接收一个字符
    elab_debug_uart_receive(input_buffer, 1);

    // 显示用户输入的字符
    char result[] = "You pressed: ";
    elab_debug_uart_send(result, sizeof(result) - 1);
    elab_debug_uart_send(input_buffer, 1);
    elab_debug_uart_send("\n", 1);

    return 0;
}
