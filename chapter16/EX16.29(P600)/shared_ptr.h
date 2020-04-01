
#include<functional>
#include"Delete.h"
using std::function;
namespace EX16_28_a
{
	template<typename>class shared_ptr;

	template<typename T>
	void swap(shared_ptr<T>& lhs, shared_ptr<T>& rhs);

	template<typename T>class shared_ptr
	{
		friend void swap<T>(shared_ptr<T>& lhs, shared_ptr<T>& rhs);
	public:
		shared_ptr():
			pointer(nullptr),use(new unsigned(1)),deleter(Delete()){}
		shared_ptr(T* ptr)
			:pointer(ptr),use(new unsigned(1)),deleter(Delete()){}
		shared_ptr(const shared_ptr& rhs)
			:pointer(rhs.pointer), use(rhs.use), deleter(rhs.deleter)
		{
			++* use;
		}
		shared_ptr(shared_ptr&& rhs)noexcept
			:pointer(rhs.pointer), use(rhs.usr), deleter(std::move(rhs.deleter))
		{
			rhs.pointer = nullptr;
			rhs.use = nullptr;
		}
		shared_ptr& operator=(const shared_ptr& rhs)
		{
			++* rhs.use;
			destroy();
			pointer = rhs.pointer;
			use = rhs.use;
			deleter = rhs.deleter;
			return *this;
		}
		shared_ptr& operator=(shared_ptr&& rhs)noexcept
		{
			EX16_28_a::swap(*this, rhs);
			rhs.destroy();
			return *this;
		}
		operator bool()const
		{
			return pointer ? true : false;
		}
		T& operator*()const
		{
			return *pointer;
		}
		T* operator->()const
		{
			return &*pointer;
		}
		unsigned use_count()const
		{
			return *use;
		}
		auto get()const
		{
			return pointer;
		}
		bool unique()const
		{
			return *use == 1;
		}
		void swap(shared_ptr& rhs)
		{
			swap(*this, rhs);
		}
		void reset() { destroy(); }
		auto reset(T* ptr)
		{
			if (ptr != pointer)
			{
				destroy();
				pointer = ptr;
				use = new unsigned(1);
			}
		}
		void reset(T* ptr, const function<void(T*)>& func)
		{
			deleter = func;
			reset(ptr);
			
		}
		~shared_ptr() { destroy(); }

	private:
		T* pointer;
		unsigned* use;
		function<void(T*)>deleter;
		void destroy()
		{
			if (pointer && (-- * use == 0))
			{
				delete use;
				deleter(pointer);
			}
			else if (!pointer)
				delete use;
			use = nullptr;
			pointer = nullptr;
		}
	};
	template<typename T>
	void swap(shared_ptr<T>& lhs, shared_ptr<T>& rhs)
	{
		using std::swap;
		swap(lhs.pointer, rhs.pointer);
		swap(lhs.use, rhs.use);
		swap(lhs.deleter, rhs.deleter);
	}
}
