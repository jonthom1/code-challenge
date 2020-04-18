package codechallenge.interfaces;

import java.util.Set;

public interface SubsInterface {
	
	public void follow(final String follower, final String followed);
	public Set<String> followedBy(final String follower);
}
