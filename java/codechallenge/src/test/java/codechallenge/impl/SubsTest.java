package codechallenge.impl;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.util.Set;

import org.junit.Before;
import org.junit.Test;

import codechallenge.interfaces.SubsInterface;

public class SubsTest {

	private SubsInterface t_subs;
	
	@Before
	public void setup() {
		t_subs = new Subs();
	}
	
	@Test
	public void test01() {
		t_subs.follow("Chris", "Alice");
		Set<String> res = t_subs.followedBy("Chris");
		
		assertEquals("Incorrect subs size", 2, res.size());
	}
	
	@Test
	public void test02() {
		t_subs.follow("Chris", "Alice");
		Set<String> res = t_subs.followedBy("Chris");
		
		assertTrue("Sub not found", res.contains("Alice"));
	}
	
	@Test
	public void test03() {
		t_subs.follow("Chris", "Alice");
		Set<String> res = t_subs.followedBy("Chris");
		
		assertFalse("Sub found when it should not be", res.contains("Bob"));
	}
	
	@Test
	public void test04() {
		t_subs.follow("Chris", "Alice");
		Set<String> res = t_subs.followedBy("Alice");
		
		assertEquals("Incorrect subs size", 1, res.size());
	}
	
	@Test
	public void test05() {
		t_subs.follow("Alice","Chris");
		Set<String> res = t_subs.followedBy("Alice");
		
		assertEquals("Incorrect subs size", 2, res.size());
	}
	
	@Test
	public void test06() {
		t_subs.follow("Alice","Chris");
		Set<String> res = t_subs.followedBy("Alice");
		
		assertTrue("Sub not found", res.contains("Chris"));
	}
	
	@Test
	public void test07() {
		t_subs.follow("Chris", "Alice");
	    t_subs.follow("Chris", "Alice");
	    t_subs.follow("Chris", "Alice");
		Set<String> res = t_subs.followedBy("Chris");
		
		assertEquals("Incorrect subs size on duplicate follows", 2, res.size());
	}
	
	@Test
	public void test08() {
		t_subs.follow("Chris", "Alice");
	    t_subs.follow("Chris", "Bob");
		Set<String> res = t_subs.followedBy("Chris");
		
		assertEquals("Incorrect subs size on multiple follows", 3, res.size());
	}
}
