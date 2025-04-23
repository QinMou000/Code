#include <iostream>
#include <jsoncpp/json/json.h>

// void parse_json_string()
// {
//     std::string json_str = R"(
//         {
//             "name": "Alice",
//             "age": 30,
//             "is_student": false,
//             "hobbies": ["reading", "coding", "travel"]
//         }
//     )";

//     Json::Value root;
//     Json::Reader reader;

//     if (!reader.parse(json_str, root))
//     {
//         std::cerr << "JSON解析错误: " /*<< reader.getFormatedErrorMessages()*/ << std::endl;
//         return;
//     }

//     std::cout << "解析结果:" << std::endl;
//     std::cout << "姓名: " << root["name"].asString() << std::endl;
//     std::cout << "年龄: " << root["age"].asInt() << std::endl;
//     std::cout << "是否学生: " << (root["is_student"].asBool() ? "是" : "否") << std::endl;

//     std::cout << "爱好: ";
//     for (const auto &hobby : root["hobbies"])
//     {
//         std::cout << hobby.asString() << " ";
//     }
//     std::cout << std::endl;
// }

// void create_json_object()
// {
//     Json::Value root;
//     root["name"] = "Bob";
//     root["age"] = 25;
//     root["is_student"] = true;

//     Json::Value hobbies;
//     hobbies.append("sports");
//     hobbies.append("music");
//     root["hobbies"] = hobbies;

//     Json::FastWriter writer;
//     std::string json_str = writer.write(root);

//     std::cout << "生成的JSON:" << std::endl;
//     std::cout << json_str << std::endl;
// }

int main() // 豆包生成
{
    int _x = 10;
    int _y = 20;
    char _oper = '+';

    Json::Value root;
    root["x"] = _x;
    root["y"] = _y;
    root["oper"] = _oper;
    Json::FastWriter writer;
    std::string s = writer.write(root);
    std::cout << s << std::endl;

    // std::cout << "=== 解析JSON字符串 ===" << std::endl;
    // parse_json_string();

    // std::cout << "\n=== 生成JSON对象 ===" << std::endl;
    // create_json_object();

    return 0;
}
