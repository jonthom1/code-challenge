package codechallenge.impl;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class UtilFunc {

	public void formatTimeDiff(final List<Entry> entries, final Date now) {
		entries.forEach(e -> {
			long mills = now.getTime() - e.getTimestamp().getTime();
			long seconds = mills/1000;
			long min = seconds/60;
	        long hours = min/60;
			
	        String res = new String();
	        
	        if(hours > 0)  {
	        	if(hours == 1) res = String.format("%d hour ago", hours);
	        	else res = String.format("%d hours ago", hours);
	        } else if( min > 0) {
	        	if(min == 1) res = String.format("%d minute ago", min);
	        	else res = String.format("%d minutes ago", min);
	        } else {
	        	if(seconds == 1) res = String.format("%d second ago", seconds);
	        	else res = String.format("%d seconds ago", seconds);
	        }

	        e.setTimediff(res);
		});
	}
	
	public List<String> formatEntries(final List<Entry> entries) {
		return formatEntriesSpec(entries, false);
	}
	
	public List<String> formatEntriesWithUser(final List<Entry> entries) {
		return formatEntriesSpec(entries, true);
	}
	
	private List<String> formatEntriesSpec(final List<Entry> entries, boolean withName) {
		List<String> res = new ArrayList<String>(entries.size());
		
		entries.forEach(e -> {
			if(withName) res.add( String.format("%s - %s (%s)", e.getUser(), e.getMessage(), e.getTimediff()) );
			else res.add( String.format("%s (%s)", e.getMessage(), e.getTimediff()) );
		});
		
		return res;
	}
}
