package codechallenge.impl;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

import codechallenge.interfaces.SubsInterface;

public class Subs implements SubsInterface {
	private Map<String, Set<String>> all_subs;
	
	public Subs() {
		super();
		
		all_subs = new HashMap<>();
	}
	
	@Override
	public void follow(String follower, String followed) {
		//If follower has no subs create new list
	    //If list exists, add to list
		
		Set<String> usubs = all_subs.getOrDefault(follower, null);
		
		if(usubs == null) {
			usubs = new HashSet<>(1);
			usubs.add(followed);
			all_subs.put(follower, usubs);
		} else {
			usubs.add(followed);
		}
		
	}

	@Override
	public Set<String> followedBy(String follower) {
		//Lookup users that the follower has subscribed
		Set<String> usubs = all_subs.getOrDefault(follower, null);
		
		if(usubs == null) { usubs = new HashSet<>(1); }
		
		//Add follower to list -- all users follow themselves
		usubs.add(follower);
		
		return usubs;
	}

	
}
