package codechallenge.impl;

import java.util.Date;

public class Entry implements Comparable<Entry> {
	private String user;
	private String message;
	private Date timestamp;
	private String timediff;
	
	public Entry(String user, String message, Date timestamp, String timediff) {
		super();
		this.user = user;
		this.message = message;
		this.timestamp = timestamp;
		this.timediff = timediff;
	}

	public Entry(Entry e) {
		super();
		this.user = e.user;
		this.message = e.message;
		this.timestamp = e.timestamp;
		this.timediff = e.timediff;
	}

	public String getUser() {
		return user;
	}

	public void setUser(String user) {
		this.user = user;
	}

	public String getMessage() {
		return message;
	}

	public void setMessage(String message) {
		this.message = message;
	}

	public Date getTimestamp() {
		return timestamp;
	}

	public void setTimestamp(Date timestamp) {
		this.timestamp = timestamp;
	}

	public String getTimediff() {
		return timediff;
	}

	public void setTimediff(String timediff) {
		this.timediff = timediff;
	}

	@Override
	public int compareTo(Entry arg0) {
		if(arg0 == null) return -1;
		return this.timestamp.compareTo(arg0.timestamp);
	}
	
	
}
