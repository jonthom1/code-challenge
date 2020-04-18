package codechallenge.interfaces;

import java.util.Date;
import java.util.List;
import java.util.Set;

import codechallenge.impl.Entry;

public interface DataInterface {
	
	public void publish(final String user, final String msg, final Date timestamp);
	public List<Entry> timeline(final String user);
	public List<Entry> timeline(final Set<String> users);
}
