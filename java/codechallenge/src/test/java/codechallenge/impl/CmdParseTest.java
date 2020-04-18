package codechallenge.impl;

import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;

public class CmdParseTest {
	
	private CmdParse t_parse;
	
	@Before
	public void setup() {
		t_parse = new CmdParse();
	}
	
	@Test
	public void test1() {
		Command t_cmd = t_parse.parse("Alice");
		
		assertEquals("Blank command not mapped correctly", Command.TIMELINE, t_cmd.getCmd());
	}
	
	@Test
	public void test2() {
		Command t_cmd = t_parse.parse("Alice");
		
		assertEquals("User not mapped correctly", "Alice", t_cmd.getUser());
	}
	
	@Test
	public void test3() {
		Command t_cmd = t_parse.parse("Alice");
		
		assertEquals("Message not parsed correctly", "", t_cmd.getMessage());
	}
	
	@Test
	public void test4() {
		Command t_cmd = t_parse.parse("Alice -> I love the weather today.");
		
		assertEquals("Message not parsed correctly", "I love the weather today.", t_cmd.getMessage());
	}
	
	@Test
	public void test5() {
		Command t_cmd = t_parse.parse("Alice -> I love the weather today.");
		
		assertEquals("Command not mapped correctly", Command.PUBLISH, t_cmd.getCmd());
	}
	
	@Test
	public void test6() {
		Command t_cmd = t_parse.parse("Alice -> I love the weather today.");
		
		assertEquals("User not parsed correctly", "Alice", t_cmd.getUser());
	}
	
	@Test
	public void test7() {
		Command t_cmd = t_parse.parse("Bob wall");
		
		assertEquals("Message not parsed correctly", "", t_cmd.getMessage());
	}
	
	@Test
	public void test8() {
		Command t_cmd = t_parse.parse("Bob -> Hello");
		
		assertEquals("Message not parsed correctly", "Hello", t_cmd.getMessage());
	}
}
