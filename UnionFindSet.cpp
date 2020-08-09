// CSDN
// https://blog.csdn.net/weixin_44895008/article/details/107893555

class UnionFindSet{
public:
	//  初始化并查集结构
	// 其中 n 表示节点范围
	UnionFindSet(size_t n)
	{
		// 初始化每一个节点都是双亲
		// 当初始化每一个节点都是双亲，且为一棵树的时候，自身是根节点且这棵树上只有一个节点
		_v.resize(n, -1);
	}

	// 找当前节点的根
	// 给一个元素的编号，找到该元素所在集合的名称
	int FindRoot(int el)
	{
		// 如果数组中存储的是负数，找到，否则一直找
		while (_v[el] >= 0)
		{
			el = _v[el];
		}
		return el;
	}

	// 并查集的合并
	bool Union(int el1, int el2)
	{
		int root1 = FindRoot(el1);
		int root2 = FindRoot(el2);

		// 两个元素在同一个集合，还合并个屁
		if (root1 == root2)
		{
			return false;
		}
		// 将两个集合中的元素合并，因此可以得到一棵树下的元素总和
		_v[root1] += _v[root2];
		// 将其中一个集合名称改变为另外一个
		_v[root2] = root1;
		return true;
	}

	// 数组中的负数的个数，即为集合的个数
	size_t size() const
	{
		int cnt = 0;
		for (auto& e : _v)
		{
			if (e < 0)
				++cnt;
		}
		return cnt;
	}

	// 判断两个节点是否在一个集合
	// 根据是否是同一个根，如果是则是同一个集合，否则不是
	bool isSameUnion(int el1, int el2)
	{
		return FindRoot(el1) == FindRoot(el2);
	}
private:
	vector<int> _v;
};