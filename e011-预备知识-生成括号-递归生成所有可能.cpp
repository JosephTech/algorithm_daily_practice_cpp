/*
n组括号，使用递归生成所有可能
*/

#include <iostream> //pause用的
#include <string> // string用的
#include <vector> // 存结果用的

void generate(std::string item, 
				int n,
				std::vector<std::string> &result) { //传入string， 几组括号n,  result向量的引用
	if (item.size() == 2*n) { //递归结束， 字符串的长度== 2n
		result.push_back(item); //够长度了，就放到result中
		return;
	}
	generate(item + "(", n, result); //字符串拼接。 用参数控制选左括号还是右括号
	generate(item + ")", n, result);
	//此处用回溯法也可以
}

int main() {
	std::vector<std::string> result; //创建数组，待会存放结果

	generate("", 2, result); // 递归调用。传入空字符串，2组括号，结果vector

	//打印
	for (int i = 0; i < result.size(); i++) {
		printf("%s\n", result[i].c_str()); 
		//c_str()函数返回一个指向正规c字符串的指针,
		//内容和string类的本身对象是一样的,
		//通过string类的c_str()函数能够把string对象转换成c中的字符串的样式
	}
	// 注意：换成c字符串样式，才能正确打印，不知道为啥
	system("pause");
	return 0;
}