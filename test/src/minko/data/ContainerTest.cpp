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

#include "ContainerTest.hpp"

using namespace minko::data;
/*
TEST_F(ContainerTest, Create)
{
	try
	{
		auto c = Container::create();
	}
	catch (...)
	{
		ASSERT_TRUE(false);
	}
}

TEST_F(ContainerTest, AddProvider)
{
	auto c = Container::create();
	auto p = Provider::create("test");

	p->set("foo", 42);

	c->addProvider(p);

	ASSERT_TRUE(c->hasProvider(p));
	ASSERT_TRUE(c->hasProperty("foo"));
	ASSERT_EQ(c->get<int>("foo"), 42);
}

TEST_F(ContainerTest, RemoveProvider)
{
	auto c = Container::create();
	auto p = Provider::create("test");

	p->set("foo", 42);

	c->addProvider(p);
	c->removeProvider(p);

	ASSERT_FALSE(c->hasProvider(p));
	ASSERT_FALSE(c->hasProperty("foo"));
}

TEST_F(ContainerTest, PropertyAdded)
{
	auto c = Container::create();
	auto p = Provider::create("test");
	int v = 0;

	p->set("foo", 42);

	auto _ = c->propertyAdded()->connect(
		[&](Container::Ptr container, const std::string& propertyName)
		{
			if (container == c && propertyName == "foo")
				v = container->get<int>("foo");
		}
	);

	c->addProvider(p);

	ASSERT_EQ(v, 42);
}

TEST_F(ContainerTest, PropertyRemoved)
{
	auto c = Container::create();
	auto p = Provider::create("test");
	int v = 0;

	p->set("foo", 42);

	auto _ = c->propertyAdded()->connect(
		[&](Container::Ptr container, const std::string& propertyName)
		{
			if (container == c && propertyName == "foo")
				v = 42;
		}
	);

	c->addProvider(p);
	c->removeProvider(p);

	ASSERT_EQ(v, 42);
}

TEST_F(ContainerTest, propertyChangedWhenAdded)
{
	auto c = Container::create();
	auto p = Provider::create("test");
	int v = 0;

	p->set("foo", 42);

	auto _ = c->propertyChanged("foo")->connect(
		[&](Container::Ptr container, const std::string& propertyName)
		{
			if (container == c && propertyName == "foo")
				v = container->get<int>("foo");
		}
	);

	c->addProvider(p);

	ASSERT_EQ(v, 42);
}

TEST_F(ContainerTest, propertyChangedWhenAddedOnProvider)
{
	auto c = Container::create();
	auto p = Provider::create("test");
	int v = 0;

	c->addProvider(p);

	auto _ = c->propertyChanged("foo")->connect(
		[&](Container::Ptr container, const std::string& propertyName)
		{
			if (container == c && propertyName == "foo")
				v = container->get<int>("foo");
		}
	);

	p->set("foo", 42);

	ASSERT_EQ(v, 42);
}

TEST_F(ContainerTest, propertyChangedWhenSetOnProvider)
{
	auto c = Container::create();
	auto p = Provider::create("test");
	int v = 0;

	c->addProvider(p);
	p->set("foo", 23);

	auto _ = c->propertyChanged("foo")->connect(
		[&](Container::Ptr container, const std::string& propertyName)
		{
			if (container == c && propertyName == "foo")
				v = container->get<int>("foo");
		}
	);

	p->set("foo", 42);

	ASSERT_EQ(v, 42);
}

TEST_F(ContainerTest, propertyChangedNot)
{
	auto c = Container::create();
	auto p = Provider::create("test");
	int v = 0;

	c->addProvider(p);
	p->set("foo", 42);

	auto _ = c->propertyChanged("foo")->connect(
		[&](Container::Ptr container, const std::string& propertyName)
		{
			if (container == c && propertyName == "foo")
				v = container->get<int>("foo");
		}
	);

	p->set("foo", 42);

	ASSERT_NE(v, 42);
}
*/