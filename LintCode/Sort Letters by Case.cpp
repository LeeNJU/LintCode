#include<string>
//题目描述：给定一个字符串只包含大小写字符，对字符串进行操作，使得小写字符在前面，大写字符在后面
//解法描述：逐步把大写字符交换到最后

void sortLetters(std::string &letters)
{
	for (int i = 0, j = letters.size(); i < j;)
	{
		if (letters[i] < 'a')
			std::swap(letters[i], letters[--j]);
		else
			++i;
	}
}