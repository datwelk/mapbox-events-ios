#import <Foundation/Foundation.h>

@protocol MMEEventConfigProviding;

NS_ASSUME_NONNULL_BEGIN

/*! @brief Factory for building URLRequests with shared components provided by Config */
@interface MMENSURLRequestFactory : NSObject

@property (nonatomic, strong, readonly) id <MMEEventConfigProviding> config;

// MARK: - Initializers

- (instancetype)init NS_UNAVAILABLE;

/**
 * Initializes and returns an NSURLRequestFactory object
 *
 * @param config A datasource providing shared values to configure URLRequests such as accessToken
 */
- (instancetype)initWithConfig:(id <MMEEventConfigProviding>)config;

// MARK: - Requests

/**
 * Constructs an NSURLRequest for Data Tasks
 *
 * @param method HTTP Verb of the request
 * @param baseURL Base URL for the quest
 * @param path Path appended to baseURL
 * @param additionalHeaders Additional headers other than those provided by config to compose request as necessary
 * @param shouldGZIP Whether or not the JSON should be GZipped
 * @param jsonObject JSON Object Body (Encoded via NSJSONSerialization)
 * @param error Reference to optional JSONSerialization Error
 */
- (nullable NSURLRequest*)urlRequestWithMethod:(NSString*)method
                                       baseURL:(NSURL*)baseURL
                                          path:(NSString*)path
                             additionalHeaders:(NSDictionary<NSString*, NSString*>*)additionalHeaders
                                    shouldGZIP: (BOOL) shouldGZIP
                                    jsonObject: (nullable id)jsonObject
                                         error:(NSError **)error;

/**
 * Constructs an NSURLRequest for Multipart Form Data
 *
 * @param method HTTP Verb of the request
 * @param baseURL Base URL for the quest
 * @param path Path appended to baseURL
 * @param additionalHeaders Additional headers other than those provided by config to compose request as necessary
 * @param data MultiPart Data
 * @param boundary Multipart Data boundary
 */
- (nullable NSURLRequest*)multipartURLRequestWithMethod:(NSString*)method
                                               baseURL:(NSURL*)baseURL
                                                  path:(NSString*)path
                                     additionalHeaders:(NSDictionary<NSString*, NSString*>*)additionalHeaders
                                                  data: (NSData*)data
                                               boundary:(NSString *)boundary;

/**
 * Constructs an NSURLRequest
 *
 * @param method HTTP Verb of the request
 * @param baseURL Base URL for the quest
 * @param path Path appended to baseURL
 * @param additionalHeaders Additional headers other than those provided by config to compose request as necessary
 * @param data HTTP Body Data
 */
- (nullable NSURLRequest*)urlRequestWithMethod:(NSString*)method
                                       baseURL:(NSURL*)baseURL
                                          path:(NSString*)path
                             additionalHeaders:(NSDictionary<NSString*, NSString*>*)additionalHeaders
                                      httpBody: (NSData*)data;

@end

NS_ASSUME_NONNULL_END