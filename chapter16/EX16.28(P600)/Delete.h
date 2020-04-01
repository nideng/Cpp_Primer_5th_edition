
namespace EX16_28_a
{
	class Delete
	{
	public:
		template<typename T>
		void operator()(T* p)const
		{
			delete p;
		}
	};
}
