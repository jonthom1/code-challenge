package codechallenge.impl;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import java.util.Date;
import java.util.List;

import org.junit.Before;
import org.junit.Test;

import codechallenge.interfaces.DataInterface;

public class DataTest {

	private DataInterface t_data;
	
	@Before
	public void setup() {
		t_data = new Data();
	}
	
	@Test
	public void test01() {
		Date t_time = new Date(0);
		
		t_data.publish("Alice", "I love the weather today.", t_time);
	    List<Entry> t_timeline = t_data.timeline("Alice");
		
	    assertTrue("Timeline should not be null", t_timeline != null);
	}
	
	@Test
	public void test02() {
		Date t_time = new Date(0);
		
		t_data.publish("Alice", "I love the weather today.", t_time);
	    List<Entry> t_timeline = t_data.timeline("Alice");
		
	    assertEquals("Incorrect timeline size", 1, t_timeline.size());
	}
	
	@Test
	public void test03() {
		Date t_time = new Date(0);
		
		t_data.publish("Alice", "I love the weather today.", t_time);
	    List<Entry> t_timeline = t_data.timeline("Alice");
		
	    assertEquals("Incorrect timeline user", "Alice", t_timeline.get(0).getUser());
	}
	
	@Test
	public void test04() {
		Date t_time = new Date(0);
		
		t_data.publish("Alice", "I love the weather today.", t_time);
	    List<Entry> t_timeline = t_data.timeline("Alice");
		
	    assertEquals("Incorrect timeline message", "I love the weather today.", t_timeline.get(0).getMessage());
	}
	
	@Test
	public void test05() {
		Date t_time = new Date(0);
		
		t_data.publish("Alice", "I love the weather today.", t_time);
	    List<Entry> t_timeline = t_data.timeline("Alice");
		
	    assertEquals("Incorrect timeline timestamp", t_time, t_timeline.get(0).getTimestamp());
	}
	
	@Test
	public void test06() {
		Date t_time = new Date(0);
		
		t_data.publish("Alice", "I love the weather today.", t_time);
	    t_data.publish("Alice", "I love the weather again.", t_time);
	    List<Entry> t_timeline = t_data.timeline("Alice");
		
	    assertEquals("Incorrect timeline size", 2, t_timeline.size());
	}
	
	@Test
	public void test07() {
		Date t_time = new Date(0);
		
		t_data.publish("Alice", "I love the weather today.", t_time);
	    t_data.publish("Alice", "I love the weather again.", t_time);
	    List<Entry> t_timeline = t_data.timeline("Alice");
		
	    assertEquals("Incorrect timeline user 0", "Alice", t_timeline.get(0).getUser());
	    assertEquals("Incorrect timeline user 1", "Alice", t_timeline.get(1).getUser());
	}
	
	@Test
	public void test08() {
		Date t_time = new Date(0);
		
		t_data.publish("Alice", "I love the weather today.", t_time);
	    t_data.publish("Alice", "I love the weather again.", t_time);
	    List<Entry> t_timeline = t_data.timeline("Alice");
		
	    assertEquals("Incorrect timeline message", "I love the weather again.", t_timeline.get(1).getMessage());
	}
	
	@Test
	public void test09() {
		Date t_time = new Date(0);
		
		t_data.publish("Bob", "Hello.", t_time);
		List<Entry> t_timeline = t_data.timeline("Alice");
		
	    assertEquals("Incorrect timeline size", 0, t_timeline.size());
	}
	
	@Test
	public void test10() {
		Date t_time = new Date(0);
		
		t_data.publish("Bob", "Hello.", t_time);
		List<Entry> t_timeline = t_data.timeline("Bob");
		
	    assertEquals("Incorrect timeline size", 1, t_timeline.size());
	}
	
	@Test
	public void test11() {
		Date t_time = new Date(0);
		
		t_data.publish("Bob", "Hello.", t_time);
		List<Entry> t_timeline = t_data.timeline("Bob");
		
	    assertEquals("Incorrect timeline user", "Bob", t_timeline.get(0).getUser());
	}
	
	@Test
	public void test12() {
		Date t_time = new Date(0);
		
		t_data.publish("Alice", "I love the weather today.", t_time);
	    t_data.publish("Bob", "Hello.", t_time);
	    t_data.publish("Alice", "I love the weather again.", t_time);
	    
	    List<Entry> t_timeline = t_data.timeline("Bob");
		
	    assertEquals("Incorrect timeline size", 1, t_timeline.size());
	}
	
	@Test
	public void test13() {
		Date t_time = new Date(0);
		
		t_data.publish("Alice", "I love the weather today.", t_time);
	    t_data.publish("Bob", "Hello.", t_time);
	    t_data.publish("Alice", "I love the weather again.", t_time);
	    
	    List<Entry> t_timeline = t_data.timeline("Alice");
		
	    assertEquals("Incorrect timeline size", 2, t_timeline.size());
	}
	
	@Test
	public void test14() {
		Date t_time1 = new Date(0);
		Date t_time2 = new Date(2000);
		
		t_data.publish("Alice", "I love the weather today.", t_time1);
	    t_data.publish("Alice", "I love the weather again.", t_time2);

	    List<Entry> t_timeline = t_data.timeline("Alice");
		
	    assertEquals("Timelime messages out of order", "I love the weather again.", t_timeline.get(0).getMessage());
	}
}
