/*
Copyright (c) 2013 Aerys

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

#include "minko/Common.hpp"
#include "minko/data/MacroBinding.hpp"

namespace minko
{
	namespace render
	{
		class ProgramSignature
		{
        private:
            typedef int MaskType;

		private:
			uint				                    _mask;
            std::vector<int>	                    _values;
            std::vector<data::MacroBinding::State>  _states;
            std::vector<std::string>                _macros;

		public:
			ProgramSignature(const data::MacroBindingMap&                           macroBindings,
                             const std::unordered_map<std::string, std::string>&    variables,
						     std::shared_ptr<data::Container>                       targetData,
                             std::shared_ptr<data::Container>		                rendererData,
                             std::shared_ptr<data::Container>                       rootData);
			
			bool 
			operator==(const ProgramSignature&) const;

			inline
			uint
			mask() const
			{
				return _mask;
			}

			inline
			const std::vector<int>&
			values() const
			{
				return _values;
			}

            inline
			const std::vector<data::MacroBinding::State>&
			states() const
			{
				return _states;
			}

            void
            updateProgram(Program& program) const;
		};
	}
}

namespace std
{
	template<>
    struct hash<minko::render::ProgramSignature>
	{
		inline
		size_t 
		operator()(const minko::render::ProgramSignature& x) const
		{
			size_t seed = std::hash<minko::uint>()(x.mask());
            auto i = 0u;

            for (auto value : x.values())
                hash_combine(seed, (x.mask() >> i) != 0 ? value : 0);

			return seed;
		}
	};
}
