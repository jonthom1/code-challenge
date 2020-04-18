package codechallenge.impl;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import codechallenge.interfaces.DataInterface;

public class Data implements DataInterface {
	private Map<String, List<Entry>> all_tl;
	
	public Data() {
		all_tl = new HashMap<>();
	}
	
	@Override
	public void publish(String user, String msg, Date timestamp) {
		Entry newEntry = new Entry(user,msg,timestamp,null);
		
		List<Entry> lookup = all_tl.getOrDefault(user, null);
		
		//If user has no history create a new one, otherwise add to existing
		if(lookup == null) {
			lookup = new ArrayList<>(1);
			lookup.add(newEntry);
			all_tl.put(user, lookup);
		} else {
			lookup.add(newEntry);
		}
		
	}

	@Override
	public List<Entry> timeline(String user) {
		Set<String> users = new HashSet<>();
		users.add(user);
		return timeline(users);
	}

	@Override
	public List<Entry> timeline(Set<String> users) {
		List<Entry> ret = new ArrayList<>();
		
		for( String user : users ) {
			List<Entry> lookup = all_tl.getOrDefault(user, null);
			
			if(lookup != null) {
				lookup.forEach( e -> { ret.add(new Entry(e)); } );
			} 
		}
		
		Collections.sort(ret, Collections.reverseOrder());
		
		return ret;
	}

}
