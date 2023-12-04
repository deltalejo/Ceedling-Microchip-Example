require('ceedling')

# Folders containing platform and hardware variants
PLATFORMS_PATH = 'platforms'.freeze
TARGETS_PATH = 'targets'.freeze

# Set defaults
DEFAULT_PLATFORM = 'host'.freeze
DEFAULT_TARGET = 'PIC16F1936'.freeze

platform = DEFAULT_PLATFORM
target = DEFAULT_TARGET.upcase()

# Get platform and target from arguments
ARGV&.each do |arg|
	case arg
	when /^platform:(\w+)/
		platform = $1
	when /^target:(\w+)/
		target = $1.upcase()
	end
end

PLATFORM = platform
TARGET = target

# Tell Ceedling to load selected platform and target configuration files
ENV['CEEDLING_USER_PROJECT_FILE'] = File.join(PLATFORMS_PATH, "#{PLATFORM}.yml")
ENV['CEEDLING_MIXIN_PROJECT_FILES'] = File.join(TARGETS_PATH, "#{TARGET}.yml")

# Load Ceedling project
Ceedling.load_project

# Dummy tasks to stop Ceedling complaining about unknown tasks when giving
# platform:<platform> and/or target:<target> arguments
rule /^platform.*/
rule /^target.*/
