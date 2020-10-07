# Time Tracker Thing

This repo is a starting point for an application that allows you to track time.

It is supposed to:

- provide easy way to track time spent on stationary activities without having to use an app
  - this should be achieved by allowing some object position manipulation to indicate different activities
- integrate with popular time trackers like toggl or jira timer or similar
- allow visualizing the data to make better decisions about your actions

There are different implementations feasible.
For now we will probably focus on building an object with NFC markers.
An app will allow assigning activities to those markers and object position will indicate tracking.

This will likely be a mono-repo of different pieces of software that will make up the final product.
At the start there'll only be a single mobile app, but who knows where we end up.
