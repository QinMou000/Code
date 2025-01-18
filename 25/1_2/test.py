# Please install OpenAI SDK first: `pip3 install openai`

from openai import OpenAI

choose = input('please choose the api key: 1 for deepseek, 2 for openai: ')
if choose == '1':
    client = OpenAI(api_key="sk-da819c7053db4723a5ae4c6dc6e7bb10", base_url="https://api.deepseek.com")
    while True:
        que = input("please input your question:")
        messages=[
            {"role": "system", "content": "你是一个助手"},
            {"role": "user", "content": que}
        ]
        response = client.chat.completions.create(
        model="deepseek-chat",
        messages=messages,
        stream=False
        )
        print(response.choices[0].message.content)
        messages.append(response.choices[0].message)
elif choose == '2':
    client = OpenAI(
    api_key="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"
    )
    while True:
        que = input('please input your question:')
        messages=[{"role": "user", "content": que}]
        completion = client.chat.completions.create(
            model="gpt-4o-mini",
            store=True,
            messages=messages, 
        )
        print(completion.choices[0].message.content)
        messages.append(completion.choices[0].message)

# from openai import OpenAI
# client = OpenAI(api_key="sk-da819c7053db4723a5ae4c6dc6e7bb10", base_url="https://api.deepseek.com")

# # Round 1
# messages = [{"role": "user", "content": "What's the highest mountain in the world?"}]
# response = client.chat.completions.create(
#     model="deepseek-chat",
#     messages=messages
# )

# messages.append(response.choices[0].message)
# print(f"Messages Round 1: {messages}")

# # Round 2
# messages.append({"role": "user", "content": "What is the second?"})
# response = client.chat.completions.create(
#     model="deepseek-chat",
#     messages=messages
# )

# messages.append(response.choices[0].message)
# print(f"Messages Round 2: {messages}")