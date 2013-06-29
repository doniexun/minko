#pragma once

#include "minko/Common.hpp"

namespace
{
	using namespace minko::render::context;
	using namespace minko::scene::data;
}

namespace minko
{
	namespace render
	{
		class DrawCall
		{
		public:
			typedef std::shared_ptr<DrawCall> Ptr;

		private:
			typedef std::shared_ptr<AbstractContext>	AbsCtxPtr;

		private:
			std::shared_ptr<DataBindings>						_bindings;
			const std::unordered_map<std::string, std::string>&	_inputNameToBindingName;

			std::vector<std::function<void(AbsCtxPtr)>>			_func;

		public:
			static inline
			Ptr
			create(std::shared_ptr<DataBindings> bindings, const std::unordered_map<std::string, std::string>& inputNameToBindingName)
			{
				return std::shared_ptr<DrawCall>(new DrawCall(bindings, inputNameToBindingName));
			}

			void
			render(std::shared_ptr<AbstractContext> context);

			void
			initialize(std::shared_ptr<DataBindings> bindings, const std::map<std::string, std::string>& inputNameToBindingName);

		private:
			DrawCall(std::shared_ptr<DataBindings> bindings, const std::unordered_map<std::string, std::string>& inputNameToBindingName);

			void
			bind(std::shared_ptr<DataBindings> bindings);
		};		
	}
}
