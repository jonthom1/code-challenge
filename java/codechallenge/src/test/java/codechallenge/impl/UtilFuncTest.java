package codechallenge.impl;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import org.junit.Before;
import org.junit.Test;

public class UtilFuncTest {

	private UtilFunc t_util;
	
	@Before
	public void setup() {
		t_util = new UtilFunc();
	}
	
	@Test
	public void test01() {
		List<Entry> entries = new ArrayList<>(1);
		entries.add(new Entry("","",new Date(0),null));
		
		t_util.formatTimeDiff(entries, new Date(2000));
		
		assertEquals("Time difference format incorrect", "2 seconds ago", entries.get(0).getTimediff());
	}
	
	@Test
	public void test02() {
		List<Entry> entries = new ArrayList<>(1);
		entries.add(new Entry("","",new Date(0),null));
		
		t_util.formatTimeDiff(entries, new Date(1000));
		
		assertEquals("Time difference format incorrect", "1 second ago", entries.get(0).getTimediff());
	}
	
	@Test
	public void test03() {
		List<Entry> entries = new ArrayList<>(1);
		entries.add(new Entry("","",new Date(0),null));
		
		t_util.formatTimeDiff(entries, new Date(1500));
		
		assertEquals("Time difference format incorrect", "1 second ago", entries.get(0).getTimediff());
	}
	
	@Test
	public void test04() {
		List<Entry> entries = new ArrayList<>(1);
		entries.add(new Entry("","",new Date(0),null));
		
		t_util.formatTimeDiff(entries, new Date(60000));
		
		assertEquals("Time difference format incorrect", "1 minute ago", entries.get(0).getTimediff());
	}
	
	@Test
	public void test05() {
		List<Entry> entries = new ArrayList<>(1);
		entries.add(new Entry("","",new Date(0),null));
		
		t_util.formatTimeDiff(entries, new Date(120000));
		
		assertEquals("Time difference format incorrect", "2 minutes ago", entries.get(0).getTimediff());
	}
	
	@Test
	public void test06() {
		List<Entry> entries = new ArrayList<>(1);
		entries.add(new Entry("","",new Date(0),null));
		
		t_util.formatTimeDiff(entries, new Date(3600000));
		
		assertEquals("Time difference format incorrect", "1 hour ago", entries.get(0).getTimediff());
	}
	
	@Test
	public void test07() {
		List<Entry> entries = new ArrayList<>(1);
		entries.add(new Entry("","",new Date(0),null));
		
		t_util.formatTimeDiff(entries, new Date(7200000));
		
		assertEquals("Time difference format incorrect", "2 hours ago", entries.get(0).getTimediff());
	}
	
	@Test
	public void test08() {
		List<Entry> entries = new ArrayList<>(1);
		entries.add(new Entry("","",new Date(0),null));
		t_util.formatTimeDiff(entries, new Date(2000));
		
		List<String> res = t_util.formatEntries(entries);
		
		assertTrue("Entry formatting vector should not be null", res != null);
	}

	@Test
	public void test09() {
		List<Entry> entries = new ArrayList<>(1);
		entries.add(new Entry("","",new Date(0),null));
		t_util.formatTimeDiff(entries, new Date(2000));
		
		List<String> res = t_util.formatEntries(entries);
		
		assertEquals("Entry formatting vector incorrect size", 1, res.size());
	}
	
	@Test
	public void test10() {
		List<Entry> entries = new ArrayList<>(1);
		entries.add(new Entry("Alice","Hello",new Date(0),null));
		t_util.formatTimeDiff(entries, new Date(2000));
		
		List<String> res = t_util.formatEntries(entries);
		
		assertEquals("Entry formatting incorrect", "Hello (2 seconds ago)", res.get(0));
	}
}
